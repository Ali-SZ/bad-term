#pragma once

#include <string>

#include "ConfigDefinitions.hpp"

class Config {
public:
  Config();
  void parseArgs(int argc, char *argv[]);
  Size findScreenSize();

  GeneralConfig generalConfig;
  FilterConfig filterConfig;
  SystemConfig systemConfig;

private:
  Size _screenSize;
  std::string _homeDir;

  uint8_t findCoreNum();
  std::string findHomeDir();
  std::string findExecDir();
};
