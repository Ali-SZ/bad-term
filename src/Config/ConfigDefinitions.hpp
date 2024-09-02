#pragma once

#include <cstdint>
#include <vector>
#include <string>

struct Size {
  uint16_t Width;
  uint16_t Height;
};

struct GeneralConfig {
    std::string videoLocation;
};

struct SystemConfig {
  uint8_t core = 1; // number of CPU's cores
};

struct FilterConfig {
  std::vector<char> charMap{' ', '.', ',', ':', 'i', 'l', 'w', '@'};
  bool reversed = false;
};
