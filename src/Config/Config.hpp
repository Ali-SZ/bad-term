#pragma once

#include <string>

#include "ConfigDefinitions.hpp"

class Config {
public:
  void findScreenSize();

  Size screenSize();

private:
  Size _screenSize;
  std::string _homeDir;

  std::string findHomeDir();
  std::string findConfigDir();
};