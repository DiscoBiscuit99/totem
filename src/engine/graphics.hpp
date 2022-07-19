#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <GLFW/glfw3.h>

#include <vector>

namespace totem {

namespace graphics {

    /**
     * @brief A struct representing color.
     */
    struct Color {
        float red;
        float green;
        float blue;
        float alpha;
    } typedef Color;

    /**
     * @brief The default clear color of the windows.
     */
    const Color DEFAULT_CLEAR_COLOR = Color{
        // A nice pinkish color
        .red = 0.75f,
        .green = 0.0f,
        .blue = 0.25f,
        .alpha = 1.0f,
    };

    const Color RED = Color{
        .red = 1.0f,
        .green = 0.0f,
        .blue = 0.0f,
        .alpha = 1.0f,
    };

    const Color GREEN = Color{
        .red = 0.0f,
        .green = 1.0f,
        .blue = 0.0f,
        .alpha = 1.0f,
    };

    const Color BLUE = Color{
        .red = 0.0f,
        .green = 0.0f,
        .blue = 1.0f,
        .alpha = 1.0f,
    };

    const Color CYAN = Color{
        .red = 0.0f,
        .green = 1.0f,
        .blue = 1.0f,
        .alpha = 1.0f,
    };

    const Color MAGENTA = Color{
        .red = 1.0f,
        .green = 0.0f,
        .blue = 1.0f,
        .alpha = 1.0f,
    };

    const Color BLACK = Color{
        .red = 0.0f,
        .green = 0.0f,
        .blue = 0.0f,
        .alpha = 1.0f,
    };

    const Color WHITE = Color{
        .red = 1.0f,
        .green = 1.0f,
        .blue = 1.0f,
        .alpha = 1.0f,
    };

    /**
     * @brief Handles window resizing appropriately.
     */
    void frame_buffer_size_callback( GLFWwindow* _, int width, int height );

    /**
     * @brief A struct holding relevant window data.
     */
    struct Window {
        GLFWwindow* glfw_window;

        Color clear_color = DEFAULT_CLEAR_COLOR;
    } typedef Window;

    /**
     * @brief Holds the instantiated windows of the application.
     */
    static std::vector<Window> WINDOWS;

    /**
     * @brief The index of the current context in the `WINDOWS` vector.
     */
    static int CURRENT_WND_IDX = 0;

    /**
     * @brief Initializes graphics related data.
     */
    void init();

    /**
     * @brief Cleans up graphics related resources.
     */
    void cleanup();

    /**
     * @brief Updates the graphics related state.
     */
    void update();

    /**
     * @brief Renders the graphics for the current context.
     */
    void render();

    /**
     * @brief Creates a new window.
     */
    void new_window( const char* title, int width, int height );

    /**
     * @brief Destroys the window of the current context.
     */
    void destroy_current_window();

    /**
     * @brief Returns the current context (meaning the `GLFWwindow` currently in
     * focus).
     *
     * @return The current context (a `GLFWwindow`).
     */
    GLFWwindow* current_context();

    /**
     * @brief Sets the current context (meaning the `GLFWwindow` currently in
     * focus).
     */
    void current_context( GLFWwindow* glfw_window );

    /**
     * @brief Sets the clear color of the current window.
     *
     * @param clear_color The new clear color.
     */
    void set_clear_color( Color clear_color );

    /**
     * @brief Clears the window.
     */
    void clear_window();

    /**
     * @brief Returns the window at the current window index in the `WINDOWS`
     * vector.
     */
    Window* current_window();

} // namespace graphics

} // namespace totem

#endif // GRAPHICS_H_
