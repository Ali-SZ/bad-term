#include "Scene.hpp"
#include "filter.hpp"

#include <opencv2/opencv.hpp>

#include <cstdio>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

Scene::Scene(Config &conf) {
  _config = conf;
  _filter = Filter(&_config);
}

void Scene::start() {
  cv::VideoCapture cap("assets/bad_apple.mp4");
  uint32_t waitTime = 1000 / cap.get(cv::CAP_PROP_FPS);

  openAltScreen();
  _running = true;

  while (_running) {
    handleInput();

    cv::Mat frame;
    if (!cap.read(frame)) {
      break;
    }
    printOnScreen(_filter.filterFrame(frame).c_str());
    usleep(waitTime * 1000);
    clearScreen();
  }

  closeAltScreen();
}

void Scene::openAltScreen() {
  initscr();
  cbreak();
  curs_set(0);
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, true);
}

void Scene::closeAltScreen() { endwin(); }

void Scene::printOnScreen(const char *content) {
  printw("%s", content);
  refresh();
}

void Scene::clearScreen() { clear(); }

void Scene::handleInput() {
  char c = getch();

  switch (c) {
  case 'q':
    _running = false;
    break;
  case 'r':
    _filter.reverse();
    break;
  }
}
