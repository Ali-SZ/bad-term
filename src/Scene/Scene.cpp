#include "Scene.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include <opencv2/opencv.hpp>

Scene::Scene(Config conf) { _config = conf; }

void Scene::start() {
  cv::VideoCapture cap("assets/bad_apple.mp4");
  uint32_t fps = 1000 / cap.get(cv::CAP_PROP_FPS);
  

  openAltScreen();

  std::string buffer;
  char ascci[8] = {' ', '.', ',', ':', 'i', 'l', 'w', '@'};
  while (cv::waitKey(1) != 'q') {
    _config.findScreenSize();
    Size size = _config.screenSize();

    cv::Mat frame;
    if (!cap.read(frame)) {
      break;
    }
    cv::Mat resized;
    cv::resize(frame, resized, cv::Size(size.Width, size.Height));
    cv::Mat gray;
    cv::cvtColor(resized, gray, cv::COLOR_RGB2GRAY);
    buffer.clear();
    system("clear");
    for (int row = 0; row < size.Height; row++) {
      for (int col = 0; col < size.Width; col++) {
        char code = (int(gray.at<unsigned char>(row, col)) >> 5);
        buffer += ascci[code];
      }
      buffer += "\n";
    }
    std::cout << buffer;
    usleep(fps * 1000);
  }

  closeAltScreen();
}

void Scene::openAltScreen() { system("echo -e \"\0337\033[?47h\""); }

void Scene::closeAltScreen() { system("echo -e \"\033[2J\033[?47l\0338\""); }

void Scene::handleInterupt() {

}