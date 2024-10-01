#include "Config.hpp"
#include "ArgParser.hpp"

#include <cstdlib>
#include <filesystem>
#include <pwd.h>
#include <sys/ioctl.h>
#include <thread>
#include <unistd.h>

Config::Config() {
  systemConfig.core = findCoreNum();
  generalConfig.videoLocation = findExecDir() + "/bad_apple.mp4";
}

void Config::parseArgs(int argc, char *argv[]) {
  ArgParser parser;
  if (!parser.parse(argc, argv)) {
    std::exit(1);
  }

  filterConfig.reversed = parser.reverse();
  generalConfig.loop = parser.loop();
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

std::string Config::findExecDir() {
  char path[FILENAME_MAX];
  ssize_t count = readlink("/proc/self/exe", path, FILENAME_MAX);
  return std::filesystem::path(std::string(path, (count > 0) ? count : 0))
      .parent_path()
      .string();
}

uint8_t Config::findCoreNum() { return std::thread::hardware_concurrency(); }
