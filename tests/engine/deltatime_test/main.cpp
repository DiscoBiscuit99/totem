#include "../../../src/engine/engine.hpp"

#include <math.h>
#include <iostream>
#include <unistd.h>

void init() {
    std::cout << "init call" << std::endl;
}

void update( time_t dt ) {
    sleep(2);
    std::cout << "update call [" << dt << "]" << std::endl;
}


void render() {
    sleep(1);
    std::cout << "render call" << std::endl;
}

int main() {
    Engine::init();

    Engine::hook_init( &init );
    Engine::hook_update( &update );
    Engine::hook_render( &render );

    Engine::run();

    return 0;
}
