#include "filter.hpp"

Filter::Filter(Config *conf) {
  _conf = conf;
  if (_conf->filterConfig.reversed) {
    reverseChars();
  }

  charMap = _conf->filterConfig.charMap;
}

std::string Filter::filterFrame(cv::Mat &frame) {
  _outputBuffer.clear();
  Size screenSize = _conf->findScreenSize();

  cv::Mat readyFrame = prepareFrame(frame, screenSize);
  matToAscii(readyFrame, screenSize);

  return _outputBuffer;
}

void Filter::reverseChars() { std::reverse(charMap.begin(), charMap.end()); }

cv::Mat Filter::prepareFrame(cv::Mat &frame, Size &size) {
  cv::Mat resized;
  cv::resize(frame, resized, cv::Size(size.Width, size.Height));
  cv::Mat gray;
  cv::cvtColor(resized, gray, cv::COLOR_RGB2GRAY);
  return gray.clone();
}

void Filter::matToAscii(cv::Mat &frame, Size &size) {
  uint8_t div = 256 / charMap.size();

  switch (frame.type()) {
  case CV_8UC1:
    for (int row = 0; row < size.Height; row++) {
      for (int col = 0; col < size.Width; col++) {
        uint8_t code = frame.at<uint8_t>(row, col) / div;
        _outputBuffer += charMap.at(code);
      }
      _outputBuffer += "\n";
    }
    break;

  case CV_8UC3:
    // for RGB frame in the future
    break;
  }
}