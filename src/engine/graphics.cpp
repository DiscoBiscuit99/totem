#include "../../includes/glad/glad.h"
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>

#include "graphics.hpp"

namespace totem {

namespace graphics {

    void frame_buffer_size_callback( GLFWwindow* _, int width, int height ) {
        glViewport( 0, 0, width, height );
    }

    void init() {
        glfwInit();
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    }

    void cleanup() { glfwTerminate(); }

    void update() {}

    void render() {
        if ( current_context() != nullptr ) {
            set_clear_color( current_window()->clear_color );
            clear_window();
            glfwSwapBuffers( current_context() );
        }
    }

    void new_window( const char* title, int width, int height ) {
        GLFWwindow* glfw_window =
            glfwCreateWindow( width, height, title, nullptr, nullptr );

        if ( glfw_window != nullptr ) {

            current_context( glfw_window );
            glfwSetFramebufferSizeCallback( glfw_window,
                                            frame_buffer_size_callback );

            WINDOWS.push_back( Window{ .glfw_window = glfw_window } );

            // Set OpenGL function pointers when the first window has spawned.
            if ( WINDOWS.size() == 1 )
                if ( !gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) ) {
                    std::cerr << "Failed to initialize GLAD." << std::endl;
                }

            std::cout << "Created new window. " << WINDOWS.size()
                      << " windows now exist." << std::endl;

        } else
            std::cerr << "Failed to create a GLFW window." << std::endl;
    }

    void destroy_current_window() {
        if ( WINDOWS.size() != 0 ) {
            glfwDestroyWindow( current_context() );

            WINDOWS.pop_back();
            glfwMakeContextCurrent( WINDOWS.end()->glfw_window );
        }
    }

    GLFWwindow* current_context() { return glfwGetCurrentContext(); }

    void current_context( GLFWwindow* glfw_window ) {
        glfwMakeContextCurrent( glfw_window );
    }

    void set_clear_color( Color clear_color ) {
        current_window()->clear_color = clear_color;
    }

    void clear_window() {
        Color color = current_window()->clear_color;

        glClearColor( color.red, color.green, color.blue, color.alpha );
        glClear( GL_COLOR_BUFFER_BIT );
    }

    Window* current_window() { return &WINDOWS.data()[CURRENT_WND_IDX]; }

} // namespace graphics

} // namespace totem
