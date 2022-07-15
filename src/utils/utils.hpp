#include <sys/time.h>
#include <ctime>

/**
 * @brief Returns the time in milliseconds.
 */
inline time_t get_time_millis() {
    return time( nullptr ) * 1000;
}
