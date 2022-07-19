#include "../../../src/engine/engine.hpp"

#include <iostream>

void init() {
    std::cout << "hi, mom" << std::endl;

    totem::graphics::new_window( "Test window", 800, 600 );
    totem::graphics::set_clear_color( totem::graphics::DEFAULT_CLEAR_COLOR );
}

void update( long dt ) {
    // std::cout << "update, dt: " << dt << std::endl;

    if ( totem::events::key_pressed( GLFW_KEY_CAPS_LOCK ) ) {
        std::cout << "CAPSLOCK WAS PRESSED!! Closing window..." << std::endl;
        totem::graphics::destroy_current_window();
    } else if ( totem::events::key_pressed( GLFW_KEY_ENTER ) ) {
        std::cout << "ENTER WAS PRESSED!! Spawning another window!"
                  << std::endl;
        totem::graphics::new_window( "Another Window", 400, 300 );
    } else if ( totem::events::key_pressed( GLFW_KEY_SPACE ) ) {
        std::cout << "SPACE WAS PRESSED!! Switching colors!" << std::endl;
        totem::graphics::set_clear_color( totem::graphics::CYAN );
    } else if ( totem::events::key_released( GLFW_KEY_SPACE ) ) {
        std::cout << "SPACE WAS RELEASED!! Switching colors!" << std::endl;
        totem::graphics::set_clear_color( totem::graphics::DEFAULT_CLEAR_COLOR );
    }

    // totem::utils::sleep( 1000 );
}

void render() {
    // std::cout << "render" << std::endl;
}

int main() {
    totem::hook_init( &init );
    totem::hook_update( &update );
    totem::hook_render( &render );

    totem::run();

    totem::cleanup();
}
