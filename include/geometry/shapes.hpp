#ifndef GEOMETRY_SHAPES_HPP
#define GEOMETRY_SHAPES_HPP

#include "figure.hpp"

#include <cmath>
#include <numbers>
#include <stdexcept>
#include <string_view>

namespace geometry {

// ============================================================================
// Circle
// ============================================================================

class Circle : public Figure {
public:
    explicit Circle(double radius) : radius_(radius) {
        if (radius_ <= 0) {
            throw std::invalid_argument("Circle radius must be positive");
        }
    }

    [[nodiscard]] double perimeter() const override {
        return 2.0 * std::numbers::pi * radius_;
    }

    [[nodiscard]] double area() const override {
        return std::numbers::pi * radius_ * radius_;
    }

    [[nodiscard]] std::string_view name() const override { return "Circle"; }

    [[nodiscard]] double radius() const { return radius_; }

private:
    double radius_;
};

// ============================================================================
// Square
// ============================================================================

class Square : public Figure {
public:
    explicit Square(double side) : side_(side) {
        if (side_ <= 0) {
            throw std::invalid_argument("Square side must be positive");
        }
    }

    [[nodiscard]] double perimeter() const override {
        return 4.0 * side_;
    }

    [[nodiscard]] double area() const override {
        return side_ * side_;
    }

    [[nodiscard]] std::string_view name() const override { return "Square"; }

    [[nodiscard]] double side() const { return side_; }

private:
    double side_;
};

// ============================================================================
// Rectangle
// ============================================================================

class Rectangle : public Figure {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {
        if (width_ <= 0 || height_ <= 0) {
            throw std::invalid_argument("Rectangle dimensions must be positive");
        }
    }

    [[nodiscard]] double perimeter() const override {
        return 2.0 * (width_ + height_);
    }

    [[nodiscard]] double area() const override {
        return width_ * height_;
    }

    [[nodiscard]] std::string_view name() const override { return "Rectangle"; }

    [[nodiscard]] double width() const { return width_; }
    [[nodiscard]] double height() const { return height_; }

private:
    double width_;
    double height_;
};

// ============================================================================
// Triangle
// ============================================================================

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {
        if (a_ <= 0 || b_ <= 0 || c_ <= 0) {
            throw std::invalid_argument("Triangle sides must be positive");
        }
        if (!isValidTriangle()) {
            throw std::invalid_argument("Invalid triangle: sides don't satisfy triangle inequality");
        }
    }

    [[nodiscard]] double perimeter() const override {
        return a_ + b_ + c_;
    }

    [[nodiscard]] double area() const override {
        // Heron's formula
        double s = perimeter() / 2.0;
        return std::sqrt(s * (s - a_) * (s - b_) * (s - c_));
    }

    [[nodiscard]] std::string_view name() const override { return "Triangle"; }

    [[nodiscard]] double sideA() const { return a_; }
    [[nodiscard]] double sideB() const { return b_; }
    [[nodiscard]] double sideC() const { return c_; }

private:
    double a_, b_, c_;

    [[nodiscard]] bool isValidTriangle() const {
        return (a_ + b_ > c_) && (b_ + c_ > a_) && (a_ + c_ > b_);
    }
};

} // namespace geometry

#endif // GEOMETRY_SHAPES_HPP
