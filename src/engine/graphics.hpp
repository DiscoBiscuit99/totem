#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <GLFW/glfw3.h>

#include <vector>

#include "color.hpp"

namespace graphics {

/**
 * @brief Initializes GLFW and the sets other relavant graphics related data.
 */
void init();

/**
 * @brief A struct containing relevant information regarding windows.
 */
struct Window {
  // The actual (glfw) window
  GLFWwindow *glfw_window;

  // Meta data pertaining to the window
  const char *title;
  int width, height;
  bool should_close;

  // Default clear color
  Color clear_color = Color{
      // A nice pinkish color
      .red = 0.75f,
      .green = 0.0f,
      .blue = 0.25f,
      .alpha = 1.0f,
  };
} typedef Window;

/**
 * @brief A vector holding all the created windows.
 */
static std::vector<Window> windows;

/**
 * @brief A struct holding only the current window (for the moment).
 */
struct GraphicsState {
  Window *current_window;
} typedef GraphicsState;

static GraphicsState graphics_state;

/**
 * @brief The resize callback.
 *
 * @param window A `GLFWwindow` for which to set the callback.
 * @param width The new width of the window.
 * @param height The new height of the window.
 */
void frame_buffer_size_callback(GLFWwindow *window, int width, int height);

/**
 * @brief Creates a window and returns either its index or an error code if a
 * GLFW window was not succesfully created.
 *
 * @param title The title of the window.
 * @param width The width of the window.
 * @param height The height of the window.
 *
 * @return The newly created window's index or an error code.
 */
int create_window(const char *title, int width, int height);

/**
 * @brief Sets the window context to the given window.
 *
 * @param window The window to make the current context.
 */
void set_current_window(Window *window);

/**
 * @brief Sets the clear color of the given window.
 *
 * @param window The window of which to set the clear color.
 * @param clear_color The clear color to set.
 */
void set_clear_color(Window *window, Color clear_color);

/**
 * @brief Returns a pointer to the current window.
 *
 * @return A pointer to the current window.
 */
Window *current_window();

} // namespace graphics

#endif // GRAPHICS_H_
