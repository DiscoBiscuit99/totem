#ifndef UTILS_H_
#define UTILS_H_

#include <chrono>
#include <thread>
#include <time.h>

namespace totem {

namespace utils {

    /**
     * @brief Returns the current time since program startup in milliseconds.
     *
     * @return The current time since program startup in milliseconds.
     */
    inline time_t get_time_millis() { return time( nullptr ) * 1000; }

    /**
     * @brief Sleeps for the amount of time given in milliseconds.
     */
    inline void sleep( int millis ) {
        std::this_thread::sleep_for( std::chrono::milliseconds( millis ) );
    }

} // namespace utils

} // namespace totem

#endif // UTILS_H_
