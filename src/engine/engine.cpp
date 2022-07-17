#include "../../includes/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "engine.hpp"

namespace engine {

inline time_t get_time_millis() { return time(nullptr) * 1000; }

void process_input(GLFWwindow *window) {
  int escape_state = glfwGetKey(window, GLFW_KEY_ESCAPE);
  int caps_state = glfwGetKey(window, GLFW_KEY_CAPS_LOCK);
  int space_state = glfwGetKey(window, GLFW_KEY_SPACE);

  if (escape_state == GLFW_PRESS || caps_state == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  // Clear color test.
  if (space_state == GLFW_PRESS) {
    state.window.clear_color[0] = 0.0f;
    state.window.clear_color[1] = 1.0f;
    state.window.clear_color[2] = 1.0f;
    state.window.clear_color[3] = 1.0f;
  }
}

void hook_update(void (*fn)(long _)) { state.user_update = fn; }
void hook_render(void (*fn)()) { state.user_render = fn; }

int init() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  state.window = create_window("test window", 800, 600);

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

  while (!state.window.should_close) {
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

  process_input(state.window.glfw_window);

  state.user_update(dt);

  state.window.should_close = glfwWindowShouldClose(state.window.glfw_window);
}

void render() {
  glClearColor(state.window.clear_color[0], state.window.clear_color[1],
               state.window.clear_color[2], state.window.clear_color[3]);
  glClear(GL_COLOR_BUFFER_BIT);

  state.user_render();

  glfwSwapBuffers(state.window.glfw_window);
}

void cleanup() {
  glfwDestroyWindow(state.window.glfw_window);
  glfwTerminate();
}

} // namespace engine
