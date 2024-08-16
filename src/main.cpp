#include <iostream>

#include "Config/Config.hpp"
#include "Scene/Scene.hpp"

int main() {
  Config config;

  Scene scene(config);
  scene.start();
}