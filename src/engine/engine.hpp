#include <sys/time.h>

namespace Engine {

    /**
     * @brief This struct stores the pointers to the functions. MIght not be needed later...
     *
     */
    struct State {
        void (*init_fn)() = nullptr;
        void (*update_fn)( time_t dt ) = nullptr;
        void (*render_fn)() = nullptr;
    } typedef State;

    static State state;

    /**
     * @brief This function is called to initialize the state of the engine.
     *
     */
    void init();

    /**
     * @brief This function hooks the given function to the state of the engine.
     * This function is called once on engine_startup
     *
     * @param fn The function pointer
     */
    void hook_init( void (*fn)() );

    /**
     * @brief This function hooks the given function to the state of the engine.
     * The delta-time is in milliseconds.
     * The given function will be called as fast as the CPU allows.
     * @param fn The function pointer
     */
    void hook_update( void (*fn)( time_t dt ) );

    /**
     * @brief This function hooks the given function to the state of the engine.
     * The given function will be called as fast as the CPU allows.
     * Spawned on a different thread, so the execution-time of the updatefunction doesn't affect when this function is called.
     * @param fn The function pointer
     */
    void hook_render( void (*fn)() );

    /**
     * @brief This function starts the engine.
     *
     */
    void run();

}

