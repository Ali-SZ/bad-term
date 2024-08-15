#include "Config.hpp"

#include <pwd.h>
#include <sys/ioctl.h>
#include <unistd.h>

void Config::findScreenSize() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  _screenSize = Size{w.ws_col, w.ws_row};
}

Size Config::screenSize() { return _screenSize; }

std::string Config::findHomeDir() {
  struct passwd *pw = getpwuid(getuid());
  std::string dir = pw->pw_dir;

  return dir;
}

std::string Config::findConfigDir() {
  return findHomeDir() + "/.config/bad-term";
}