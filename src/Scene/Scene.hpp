#pragma once

#include "../Config/Config.hpp"
#include "filter.hpp"

#include <ncurses.h>

class Scene {
public:
  Scene(Config &conf);

  void start();

private:
  Config _config;
  bool _running;
  Filter _filter;
  WINDOW *_buffer;

  void openAltScreen();
  void closeAltScreen();
  void printOnScreen(const char *content);
  void clearScreen();

  void handleInput();
};
