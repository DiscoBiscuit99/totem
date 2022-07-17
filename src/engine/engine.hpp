#ifndef ENGINE_H_
#define ENGINE_H_

#include <GLFW/glfw3.h>

#include "graphics.hpp"

namespace engine {

/**
 * @brief A struct representing the state of the engine.
 */
struct State {
  void (*user_update)(long dt);
  void (*user_render)();
} typedef State;

static State state;

// TODO: replace this with something that makes sense in the context of this
// engine.
void process_input(GLFWwindow *window);

/**
 * @brief Hooks the given function to the `update` function of the engine.
 */
void hook_update(void (*fn)(long dt));

/**
 * @brief Hooks the given function to the `render` function of the engine.
 */
void hook_render(void (*fn)());

/**
 * @brief Initializes the engine state.
 */
int init();

/**
 * @brief Runs the engine.
 * @pre Engine `update` and `render` functions must be hooked up.
 * @return An error code (0 for success).
 */
int run();

/**
 * @brief The engine's main update function.
 *
 * @param dt The delta time in milliseconds.
 */
void update(long dt);

// TODO: Move this to graphics.
/**
 * @brief The engine's main render function.
 */
void render();

/**
 * @brief Cleans up the resources before shutting down and exiting.
 */
void cleanup();

} // namespace engine

#endif // ENGINE_H_
