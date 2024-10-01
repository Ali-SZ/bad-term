#pragma once

enum Flags {
  Reverse = 0x01,
  Loop = 0x02,
};

class ArgParser {
public:
  bool parse(int argc, char *argv[]);

  bool reverse();
  bool loop();

private:
  unsigned char _flags = 0;

  void showHelp();
};
