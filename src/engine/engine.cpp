#include "../utils/utils.hpp"
#include "engine.hpp"

#include <unistd.h> // fork
#include <sys/time.h>
#include <ctime>
#include <chrono>

void Engine::init() {
    state = State{};
}

void Engine::hook_init( void (*fn)() ) {
    state.init_fn = fn;
}

void Engine::hook_update( void (*fn)( time_t dt ) ) {
    state.update_fn = fn;
}

void Engine::hook_render( void (*fn)() ) {
    state.render_fn = fn;
    // TODO: call graphics hook
}

void Engine::run() {

    state.init_fn();

    if ( fork() ) { // Might need to check for error -1

        while ( true )
            state.render_fn();

    } else {

        time_t dt = 0.0;
        time_t start;

        while ( true ) {
            start = get_time_millis();

            state.update_fn( dt );

            dt = get_time_millis() - start;
       }

    }

}
