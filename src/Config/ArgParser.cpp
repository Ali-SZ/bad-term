#include "ArgParser.hpp"

#include <iostream>
#include <string>
#include <vector>

bool ArgParser::parse(int argc, char *argv[]) {
  std::vector<std::string> args(argv + 1, argv + argc);

  for (auto it = args.begin(); it != args.end(); it++) {
    if (it->compare("--help") == 0 || it->compare("-h") == 0) {
      showHelp();
      return false;
    } else if (it->compare("--reverse") == 0 || it->compare("-r") == 0) {
      _flags |= Flags::Reverse;
    } else {
      std::cerr << "Error: Arguments are invalid\n\n";
      showHelp();
      return false;
    }
  }

  return true;
}

bool ArgParser::reverse() { return _flags & Flags::Reverse; }

void ArgParser::showHelp() {
  std::cout << "Usage: bad-term [arg [...]].\n"
            << "\nArguments:\n"
            << "  --help               -h        - Show this message and exit\n"
            << "  --reverse            -r        - Reverse the character map\n"
            << "\nRuntime keys:\n"
            << "  r                              - Reverse the character map\n"
            << "  q                              - Quit\n";
}
