#pragma once

#include "../Config/Config.hpp"
#include "filter.hpp"

class Scene {
public:
  Scene(Config &conf);

  void start();

private:
  Config _config;
  bool _running;
  Filter _filter;

  void openAltScreen();
  void closeAltScreen();
  void printOnScreen(const char *content);
  void clearScreen();

  void handleInput();
};
