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
        while ( true ) {
            // BEGIN RENDER LOOP IN SEPARATE THREAD
            state.render_fn();
            // END RENDER LOOP
        }
    } else {
        time_t dt = 0.0;
        time_t start;
        while ( true ) {
            start = time(nullptr) * 1000;
            
            // BEGIN UPDATE LOOP IN SEPARATE THREAD
            state.update_fn( dt );

            // END UPDATE LOOP
            dt = (time(nullptr) * 1000) - start;
            
            
       }
    }

    
}
