#include <time.h>

#include "engine.hpp"

namespace totem {

void hook_init( void ( *fn )() ) { USER_INIT = fn; }

void hook_update( void ( *fn )( long dt ) ) { USER_UPDATE = fn; }

void hook_render( void ( *fn )() ) { USER_RENDER = fn; }

void init() {
    graphics::init();
    USER_INIT();
    ENGINE_STATE.is_running = true;
}

void update( long dt ) {
    events::update();
    USER_UPDATE( dt );
}

void render() {
    graphics::render();
    USER_RENDER();
}

void run() {
    init();

    time_t dt = 0;
    time_t start = 0;

    while ( ENGINE_STATE.is_running ) {
        start = utils::get_time_millis();

        update( (long)dt );
        render();

        dt = utils::get_time_millis() - start;
    }

    cleanup();
}

void cleanup() { graphics::cleanup(); }

} // namespace totem
