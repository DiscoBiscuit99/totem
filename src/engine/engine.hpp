#ifndef ENGINE_H_
#define ENGINE_H_

#include <GLFW/glfw3.h>

#include "graphics.hpp"
#include "events.hpp"
#include "utils.hpp"

namespace totem {

/**
 * @brief A struct representing the state of the engine.
 */
struct State {
    bool is_running;
} typedef State;

/**
 * @brief The one and only state of the engine during the lifetime of the
 * application.
 */
static State ENGINE_STATE = State{
    .is_running = false,
};

/**
 * @brief The `init` function controlled by the user. This function is to be
 * hooked up to an `init` function defined by the user.
 */
static void ( *USER_INIT )() = nullptr;

/**
 * @brief The `update` function controlled by the user. This function is to
 * be hooked up to an `update` function defined by the user.
 */
static void ( *USER_UPDATE )( long dt ) = nullptr;

/**
 * @brief The `render` function controlled by the user. This function is to
 * be hooked up to a `render` function defined by the user.
 */
static void ( *USER_RENDER )() = nullptr;

/**
 * @brief Hooks the given function to the `USER_INIT` function.
 */
void hook_init( void ( *fn )() );

/**
 * @brief Hooks the given function to the `USER_UPDATE` function.
 */
void hook_update( void ( *fn )( long dt ) );

/**
 * @brief Hooks the given function to the `USER_RENDER` function.
 */
void hook_render( void ( *fn )() );

/**
 * @brief Initializes the state of the engine. This is to be run before
 * anthing else.
 */
void init();

/**
 * @brief Updates the state of the engine.
 */
void update( long dt );

/**
 * @brief Renders the state of the engine.
 */
void render();

/**
 * @brief Essentially the main-loop of the engine. This function calls the
 * `init` function before anything else.
 */
void run();

void cleanup();

} // namespace totem

#endif // ENGINE_H_
