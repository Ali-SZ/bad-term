#pragma once

#include <algorithm>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "../Config/Config.hpp"

class Filter {
public:
  Filter(Config *conf);

  std::string filterFrame(cv::Mat &frame);

private:
  Config *_conf;
  std::string _outputBuffer;
  std::vector<char> charMap;

  void reverseChars();
  cv::Mat prepareFrame(cv::Mat &frame, Size &size);
  void matToAscii(cv::Mat &frame, Size &size);
};