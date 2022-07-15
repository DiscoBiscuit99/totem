#include "engine.hpp"

void Engine::init() {
    state = State{};
}

void Engine::hook_init( void (*fn)() ) {
    state.init_fn = fn;
}

void Engine::hook_update( void (*fn)( double dt ) ) {
    state.update_fn = fn;
}

void Engine::hook_render( void (*fn)() ) {
    state.render_fn = fn;
    // TODO: call graphics hook
}

void Engine::run() {

    double dt = 0.001;

    state.init_fn();

    // BEGIN UPDATE LOOP IN SEPARATE THREAD
    state.update_fn( dt );
    // END UPDATE LOOP

    // BEGIN RENDER LOOP IN SEPARATE THREAD
    state.render_fn();
    // END RENDER LOOP
}
