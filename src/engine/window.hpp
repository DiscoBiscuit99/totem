#ifndef WINDOW_H_
#define WINDOW_H_

#include <GLFW/glfw3.h>

struct Window {
  GLFWwindow *glfw_window;
  const char *title;
  int width, height;
  bool should_close;
  float clear_color[4] = {
      0.75f,
      0.0f,
      0.25f,
      1.0f,
  };
} typedef Window;

void frame_buffer_size_callback(GLFWwindow *window, int width, int height);

Window create_window(const char *title, int width, int height);

void set_window(Window *window);

void set_clear_color(Window *window);

#endif // WINDOW_H_
