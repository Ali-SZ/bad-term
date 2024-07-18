#include "Config.hpp"

#include <sys/ioctl.h>
#include <unistd.h>

void Config::findScreenSize() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  _screenSize = Size{w.ws_col, w.ws_row};
}

Size Config::screenSize() {
  return _screenSize;
}