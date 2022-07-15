#include "../../src/engine/engine.hpp"
#include <math.h>
#include <iostream>
#include <unistd.h>

void update( time_t dt ) {
    // int a = 0;
    sleep(1);
    
    std::cout << "Hello, There! [" << dt << "]" << std::endl;
}


void render() {
    // std::cout << "General Kenobi!" << std::endl;
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
