#include "../../src/engine/engine.hpp"

#include <iostream>

void update( double dt ) {
    std::cout << "Hello, There!" << std::endl;
}


void render() {
    std::cout << "General Kenobi!" << std::endl;
}

void init() {

}

int main() {
    std::cout << "hi, mom" << std::endl;

    Engine::init();

    Engine::hook_init( &init );

    Engine::hook_update( &update );

    Engine::hook_render( &render );

    Engine::run();

    return 0;
}
