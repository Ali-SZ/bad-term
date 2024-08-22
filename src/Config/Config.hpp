#pragma once

#include <string>

#include "ConfigDefinitions.hpp"

class Config {
public:
  Config();
  Size findScreenSize();

  FilterConfig filterConfig;
  SystemConfig systemConfig;

private:
  Size _screenSize;
  std::string _homeDir;

  uint8_t findCoreNum();
  std::string findHomeDir();
  std::string findConfigDir();
};