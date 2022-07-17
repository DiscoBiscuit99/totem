#include "../../../src/engine/engine.hpp"

#include <iostream>

void init() { std::cout << "hi, mom" << std::endl; }

void update(long dt) { std::cout << "update, dt: " << dt << std::endl; }

void render() { std::cout << "render" << std::endl; }

int main() {
  engine::hook_update(&update);
  engine::hook_render(&render);

  return engine::run();
}
