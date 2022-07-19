#include <GLFW/glfw3.h>

#include <iostream>

#include "graphics.hpp"

namespace totem {

namespace events {

    bool key_pressed( int key_code ) {
        bool is_key_pressed = false;

        if ( graphics::current_context() != nullptr ) {
            int key_state = glfwGetKey( graphics::current_context(), key_code );

            if ( key_state == GLFW_PRESS )
                is_key_pressed = true;
        }

        return is_key_pressed;
    }

    bool key_released( int key_code ) {
        bool is_key_released = false;

        if ( graphics::current_context() != nullptr ) {
            int key_state = glfwGetKey( graphics::current_context(), key_code );

            if ( key_state == GLFW_RELEASE )
                is_key_released = true;
        }

        return is_key_released;
    }

    void update() {
        //if ( graphics::current_context() != nullptr )
            glfwPollEvents();
    }

} // namespace events

} // namespace totem
