#include "../../src/engine/engine.hpp"

#include <iostream>

void init() {
    std::cout << "hi, mom" << std::endl;
}

void update( double dt ) {
    std::cout << "update, dt: " << dt << std::endl;
}

void render() {
    std::cout << "render" << std::endl;
}

int main() {
    Engine::init();

    Engine::hook_init( &init );
    Engine::hook_update( &update );
    Engine::hook_render( &render );

    Engine::run();

    return 0;
}
