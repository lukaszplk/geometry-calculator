#ifndef GEOMETRY_FACTORY_HPP
#define GEOMETRY_FACTORY_HPP

#include "figure.hpp"
#include "shapes.hpp"

#include <istream>
#include <memory>
#include <stdexcept>
#include <string>

namespace geometry {

/// Factory for creating Figure objects from input
class FigureFactory {
public:
    /// Create a figure from type character and input stream
    /// @param type Figure type: 'c'=circle, 's'=square, 'r'=rectangle, 't'=triangle
    /// @param in Input stream to read dimensions from
    /// @return Unique pointer to created figure
    /// @throws std::invalid_argument if type is unknown or dimensions are invalid
    [[nodiscard]] static std::unique_ptr<Figure> create(char type, std::istream& in) {
        switch (type) {
            case 'c': case 'C': {
                double radius;
                in >> radius;
                return std::make_unique<Circle>(radius);
            }
            case 's': case 'S': {
                double side;
                in >> side;
                return std::make_unique<Square>(side);
            }
            case 'r': case 'R': {
                double width, height;
                in >> width >> height;
                return std::make_unique<Rectangle>(width, height);
            }
            case 't': case 'T': {
                double a, b, c;
                in >> a >> b >> c;
                return std::make_unique<Triangle>(a, b, c);
            }
            default:
                throw std::invalid_argument(
                    std::string("Unknown figure type: '") + type + "'"
                );
        }
    }
};

} // namespace geometry

#endif // GEOMETRY_FACTORY_HPP
