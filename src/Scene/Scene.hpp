#pragma once

#include "../Config/Config.hpp"

class Scene {
public:
  Scene(Config conf);

  void start();

private:
  Config _config;

  void clearScreen();
  void printFrame();
};