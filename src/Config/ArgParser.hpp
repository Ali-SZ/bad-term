#pragma once

enum Flags {
  Reverse = 0x01,
};

class ArgParser {
public:
  bool parse(int argc, char *argv[]);

  bool reverse();

private:
  unsigned char _flags = 0;

  void showHelp();
};
