namespace totem {

namespace events {

    /**
     * @brief Polls events and checks for updates.
     */
    void update();

    /**
     * @brief Returns whether the given key was pressed (in the context of the
     * current window).
     */
    bool key_pressed( int key_code );

    /**
     * @brief Returns whether the given key was released (in the context of the
     * current window).
     */
    bool key_released( int key_code );

} // namespace event

} // namespace totem
