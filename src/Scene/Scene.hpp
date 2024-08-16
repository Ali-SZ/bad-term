#pragma once

#include "../Config/Config.hpp"
#include "filter.hpp"

class Scene {
public:
  Scene(Config conf);

  void start();

private:
  Config _config;

  void openAltScreen();
  void closeAltScreen();
  void clearScreen();
};