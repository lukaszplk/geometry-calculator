#ifndef GEOMETRY_FIGURE_HPP
#define GEOMETRY_FIGURE_HPP

#include <string_view>

namespace geometry {

/// Abstract base class for geometric figures
class Figure {
public:
    virtual ~Figure() = default;

    /// Calculate the perimeter of the figure
    [[nodiscard]] virtual double perimeter() const = 0;

    /// Calculate the area of the figure
    [[nodiscard]] virtual double area() const = 0;

    /// Get the name of the figure type
    [[nodiscard]] virtual std::string_view name() const = 0;
};

} // namespace geometry

#endif // GEOMETRY_FIGURE_HPP
