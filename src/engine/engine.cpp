#include "../../includes/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "engine.hpp"
#include "graphics.hpp"

namespace engine {

/**
 * @brief Calculates the current time in milliseconds.
 *
 * @return The current time in milliseconds.
 */
inline time_t get_time_millis() { return time(nullptr) * 1000; }

void process_input(GLFWwindow *window) {
  int escape_state = glfwGetKey(window, GLFW_KEY_ESCAPE);
  int caps_state = glfwGetKey(window, GLFW_KEY_CAPS_LOCK);
  int space_state = glfwGetKey(window, GLFW_KEY_SPACE);

  // Quick debug exiting of the program.
  if (escape_state == GLFW_PRESS || caps_state == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  // Clear color test.
  if (space_state == GLFW_PRESS)
    graphics::set_clear_color(graphics::current_window(),
                              graphics::color::CYAN);
}

void hook_update(void (*fn)(long _)) { state.user_update = fn; }

void hook_render(void (*fn)()) { state.user_render = fn; }

int init() {
  graphics::init();

  // Set OpenGL function pointers.
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD." << std::endl;
    return -1;
  }

  return 0;
}

int run() {
  init();

  time_t start;
  time_t dt = get_time_millis();

  while (!graphics::current_window()->should_close) {
    start = get_time_millis();

    update((long)dt);
    render();

    dt = get_time_millis();
  }

  cleanup();

  return 0;
}

void update(long dt) {
  glfwPollEvents();

  process_input(graphics::current_window()->glfw_window);

  state.user_update(dt);

  graphics::current_window()->should_close =
      glfwWindowShouldClose(graphics::current_window()->glfw_window);
}

void render() {
  graphics::Window *current_window = graphics::current_window();
  float r = current_window->clear_color.red;
  float g = current_window->clear_color.green;
  float b = current_window->clear_color.blue;
  float a = current_window->clear_color.alpha;

  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);

  state.user_render();

  glfwSwapBuffers(current_window->glfw_window);
}

void cleanup() {
  glfwDestroyWindow(graphics::current_window()->glfw_window);
  glfwTerminate();
}

} // namespace engine
