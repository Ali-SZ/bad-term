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
  Filter filter(&_config);

  openAltScreen();

  while (true) {
    cv::Mat frame;
    if (!cap.read(frame)) {
      break;
    }

    std::cout << filter.filterFrame(frame);
    usleep(fps * 1000);
  }

  closeAltScreen();
}

void Scene::openAltScreen() { system("echo -e \"\0337\033[?47h\""); }

void Scene::closeAltScreen() { system("echo -e \"\033[2J\033[?47l\0338\""); }

void Scene::clearScreen() { system("clear"); }
