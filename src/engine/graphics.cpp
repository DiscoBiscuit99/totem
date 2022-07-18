#include "../../includes/glad/glad.h"

#include <GLFW/glfw3.h>
#include <iostream>

#include "graphics.hpp"

namespace graphics {

void init() {
    graphics_state = GraphicsState{};

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create_window("test window", 800, 600);

    // Set OpenGL function pointers.
    // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    //  std::cerr << "Failed to initialize GLAD." << std::endl;
    //}
}

void frame_buffer_size_callback(GLFWwindow *_, int width, int height) {
    glViewport(0, 0, width, height);
}

Window *create_window(const char *title, int width, int height) {
    GLFWwindow *glfw_window =
        glfwCreateWindow(800, 600, "test window", nullptr, nullptr);

    if (glfw_window == nullptr) {
        std::cerr << "Failed to create a GLFW window." << std::endl;
        glfwTerminate();
    }

    windows.push_back(Window{
        .glfw_window = glfw_window,
        .title = title,
        .width = width,
        .height = height,
        .should_close = false,
    });

    int new_wnd_idx = windows.size() - 1;
    Window *new_window = &windows.data()[new_wnd_idx];

    set_current_window(new_window);

    return new_window;
}

void set_current_window(Window *window) {
    glfwMakeContextCurrent(window->glfw_window);
    glfwSetFramebufferSizeCallback(window->glfw_window,
                                   frame_buffer_size_callback);

    graphics_state.current_window = window;
}

void set_clear_color(Window *window, Color clear_color) {
    window->clear_color = clear_color;
}

Window *current_window() { return graphics_state.current_window; }

void destroy_window(Window window) { glfwDestroyWindow(window.glfw_window); }

void cleanup() {
    while (windows.size() > 0) {
        destroy_window(*windows.end());
        windows.pop_back();
    }

    glfwTerminate();
}

} // namespace graphics
