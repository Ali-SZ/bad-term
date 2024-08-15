#include <iostream>

#include "Config/Config.hpp"
#include "Scene/Scene.hpp"

int main() {
  Config config;
  config.findScreenSize();

  Scene scene(config);
  scene.start();
}