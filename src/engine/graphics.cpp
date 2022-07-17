#include "../../includes/glad/glad.h"

#include <iostream>

#include "graphics.hpp"

namespace graphics {

void init() {
  graphics_state = GraphicsState{};

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  create_window("test window", 800, 600);
}

void frame_buffer_size_callback(GLFWwindow *_, int width, int height) {
  glViewport(0, 0, width, height);
}

int create_window(const char *title, int width, int height) {
  GLFWwindow *glfw_window =
      glfwCreateWindow(800, 600, "test window", nullptr, nullptr);

  if (glfw_window == nullptr) {
    std::cerr << "Failed to create a GLFW window." << std::endl;
    glfwTerminate();
    return -1;
  }

  windows.push_back(Window{
      .glfw_window = glfw_window,
      .title = title,
      .width = width,
      .height = height,
      .should_close = false,
  });

  int current_idx = windows.size() - 1;
  set_current_window(&windows.data()[current_idx]);

  return current_idx;
}

void set_current_window(Window *window) {
  glfwMakeContextCurrent(window->glfw_window);
  glfwSetFramebufferSizeCallback(window->glfw_window,
                                 frame_buffer_size_callback);

  graphics_state.current_window = window;

  std::cout << "window info from graphics:\n";
  std::cout << "Title: " << graphics_state.current_window->title << std::endl;
  std::cout << "width, height: " << graphics_state.current_window->width << ", "
            << graphics_state.current_window->height << std::endl;
  std::cout << "Should close(?): "
            << graphics_state.current_window->should_close << std::endl;
}

void set_clear_color(Window *window, Color clear_color) {
  window->clear_color = clear_color;
}

Window *current_window() { return graphics_state.current_window; }

} // namespace graphics
