#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "../Config/Config.hpp"

class Filter {
public:
  Filter();
  Filter(Config *conf);

  std::string filterFrame(cv::Mat &frame);
  void reverse();

private:
  Config *_conf;
  std::string _outputBuffer;
  std::vector<char> _charMap;

  void reverseCharMap();
  cv::Mat prepareFrame(cv::Mat &frame, Size &size);
  void matToAscii(cv::Mat &frame);
  std::string submatToAsciiGray(cv::Mat frame);
};
