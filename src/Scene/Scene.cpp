#include <opencv2/opencv.hpp>

#include "Scene.hpp"
#include "filter.hpp"

#include <chrono>
#include <thread>

Scene::Scene(Config &conf) {
  _config = conf;
  _filter = Filter(&_config);
}

void Scene::start() {
  cv::VideoCapture cap(_config.generalConfig.videoLocation);
  double targetFps = cap.get(cv::CAP_PROP_FPS);

  const std::chrono::nanoseconds targetTime(
      static_cast<uint64_t>(round(1.0 / targetFps * 1.0e9)));
  std::chrono::high_resolution_clock::time_point startTime, calcTime;
  std::chrono::nanoseconds elapsedTime;

  openAltScreen();
  _running = true;

  while (_running) {
    startTime = std::chrono::high_resolution_clock::now();

    handleInput();

    cv::Mat frame;
    if (!cap.read(frame)) {
      break;
    }
    clearScreen();
    printOnScreen(_filter.filterFrame(frame).c_str());

    calcTime = std::chrono::high_resolution_clock::now();
    elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
        calcTime - startTime);
    std::this_thread::sleep_for(
        std::chrono::nanoseconds(targetTime - elapsedTime));
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

  Size size = _config.findScreenSize();
  _buffer = newwin(size.Height, size.Width, 0, 0);
}

void Scene::closeAltScreen() {
  delwin(_buffer);
  endwin();
}

void Scene::printOnScreen(const char *content) {
  mvwprintw(_buffer, 0, 0, "%s", content);
  wrefresh(_buffer);
}

void Scene::clearScreen() { werase(_buffer); }

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
