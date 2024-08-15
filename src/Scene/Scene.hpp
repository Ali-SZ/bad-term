#pragma once

#include "../Config/Config.hpp"

class Scene {
public:
  Scene(Config conf);

  void start();

private:
  Config _config;

  void openAltScreen();
  void closeAltScreen();
  void clearScreen();
  void printFrame();
};