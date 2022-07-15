#include "utils.hpp"

inline time_t get_time_millis() {
    return time( nullptr ) * 1000;
}
