#include "filter.hpp"

#include <algorithm>
#include <future>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

Filter::Filter(Config *conf) {
  _conf = conf;
  if (_conf->filterConfig.reversed) {
    reverseChars();
  }

  _charMap = _conf->filterConfig.charMap;
}

std::string Filter::filterFrame(cv::Mat &frame) {
  _outputBuffer.clear();
  Size screenSize = _conf->findScreenSize();

  cv::Mat readyFrame = prepareFrame(frame, screenSize);
  matToAscii(readyFrame);

  return _outputBuffer;
}

void Filter::reverseChars() { std::reverse(_charMap.begin(), _charMap.end()); }

cv::Mat Filter::prepareFrame(cv::Mat &frame, Size &size) {
  cv::Mat resized;
  cv::resize(frame, resized, cv::Size(size.Width, size.Height));
  cv::Mat gray;
  cv::cvtColor(resized, gray, cv::COLOR_RGB2GRAY);
  return gray.clone();
}

void Filter::matToAscii(cv::Mat &frame) {
  std::vector<std::future<std::string>> futures;
  int rowSize = frame.rows / _conf->systemConfig.core;

  switch (frame.type()) {
  case CV_8UC1:
    for (int i = 0; i < _conf->systemConfig.core; i++) {
      int startRow = i * rowSize;
      int endRow =
          (i == _conf->systemConfig.core - 1) ? frame.rows : (i + 1) * rowSize;

      cv::Mat subFrame =
          cv::Mat(frame, cv::Rect(0, startRow, frame.cols, endRow - startRow));
      futures.push_back(std::async(&Filter::submatToAsciiGray, this, subFrame));
    }

    for (auto &fut : futures) {
      _outputBuffer += fut.get();
    }

    break;

  case CV_8UC3:
    // for RGB frame in the future
    break;
  }
}

std::string Filter::submatToAsciiGray(cv::Mat frame) {
  std::string result;
  uint8_t div = 256 / _charMap.size();

  for (int row = 0; row < frame.rows; row++) {
    for (int col = 0; col < frame.cols; col++) {
      uint8_t code = frame.at<uint8_t>(row, col) / div;
      result += _charMap.at(code);
    }
    result += "\n";
  }

  return result;
}