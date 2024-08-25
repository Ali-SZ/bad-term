#include "Config.hpp"

#include <argparse/argparse.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <pwd.h>
#include <sys/ioctl.h>
#include <thread>
#include <unistd.h>

Config::Config() { systemConfig.core = findCoreNum(); }

void Config::parseArgs(int argc, char *argv[]) {
  argparse::ArgumentParser program("bad-term");

  program.add_argument("-r", "--reverse")
      .help("reverses the ascii range, can be used during runtime")
      .flag();

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    std::exit(1);
  }

  filterConfig.reversed = (program["--reverse"] == true);
}

Size Config::findScreenSize() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  return Size{w.ws_col, w.ws_row};
}

std::string Config::findHomeDir() {
  struct passwd *pw = getpwuid(getuid());
  std::string dir = pw->pw_dir;

  return dir;
}

std::string Config::findConfigDir() {
  return findHomeDir() + "/.config/bad-term";
}

uint8_t Config::findCoreNum() { return std::thread::hardware_concurrency(); }
