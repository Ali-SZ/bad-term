#include "Config/Config.hpp"
#include "Scene/Scene.hpp"

int main(int argc, char *argv[]) {
  Config config;
  config.parseArgs(argc, argv);

  Scene scene(config);
  scene.start();

  return 0;
}
