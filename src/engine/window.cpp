#include "../../includes/glad/glad.h"

#include <iostream>

#include "window.hpp"

void frame_buffer_size_callback(GLFWwindow *_, int width, int height) {
  glViewport(0, 0, width, height);
}

Window create_window(const char *title, int width, int height) {
  GLFWwindow *glfw_window =
      glfwCreateWindow(800, 600, "test window", nullptr, nullptr);

  if (glfw_window == nullptr) {
    std::cerr << "Failed to create a GLFW window." << std::endl;
    glfwTerminate();
  }

  Window new_window = Window{
      .glfw_window = glfw_window,
      .title = title,
      .width = width,
      .height = height,
      .should_close = false,
  };

  set_window(&new_window);

  return new_window;
}

void set_window(Window *window) {
  glfwMakeContextCurrent(window->glfw_window);
  glfwSetFramebufferSizeCallback(window->glfw_window,
                                 frame_buffer_size_callback);
}

void set_clear_color(Window *window, float clear_color[4]) {
  glClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);
}
