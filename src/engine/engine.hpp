#include <iostream>
#include <unistd.h>

namespace Engine {

    struct State {
        void (*init_fn)() = nullptr;
        void (*update_fn)( time_t dt ) = nullptr;
        void (*render_fn)() = nullptr;
    } typedef State;

    static State state;

    void init();

    void hook_init( void (*fn)() );
    void hook_update( void (*fn)( time_t dt ) );
    void hook_render( void (*fn)() );

    void run();

}

