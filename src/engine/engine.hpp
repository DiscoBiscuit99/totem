#ifndef ENGINE_H_
#define ENGINE_H_

#include <GLFW/glfw3.h>

#include "window.hpp"

namespace engine {

struct State {
  Window window;

  void (*user_update)(long dt);
  void (*user_render)();
} typedef State;

static State state;

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

void update(long dt);
void render();

void cleanup();

} // namespace engine

#endif // ENGINE_H_
