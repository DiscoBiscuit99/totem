#ifndef COLOR_H_
#define COLOR_H_

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

namespace color {

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

} // namespace color

} // namespace graphics

#endif // COLOR_H_
