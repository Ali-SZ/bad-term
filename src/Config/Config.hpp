#pragma once

#include <string>

#include "ConfigDefinitions.hpp"

class Config {
public:
  Size findScreenSize();

  FilterConfig filterConfig;

private:
  Size _screenSize;
  std::string _homeDir;

  std::string findHomeDir();
  std::string findConfigDir();
};