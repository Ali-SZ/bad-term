#pragma once

#include "ConfigDefinitions.hpp"

class Config {
public:
  void findScreenSize();

  Size screenSize();

private:
  Size _screenSize;
};