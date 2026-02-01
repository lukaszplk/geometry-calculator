#ifndef GEOMETRY_COLLECTION_HPP
#define GEOMETRY_COLLECTION_HPP

#include "figure.hpp"

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <vector>

namespace geometry {

/// Manages a collection of figures with 1-based indexing
class FigureCollection {
public:
    /// Add a figure to the collection
    void add(std::unique_ptr<Figure> figure) {
        figures_.push_back(std::move(figure));
    }

    /// Get a figure by 1-based index
    /// @param index 1-based index
    /// @throws std::out_of_range if index is invalid
    [[nodiscard]] const Figure& get(std::size_t index) const {
        if (index == 0 || index > figures_.size()) {
            throw std::out_of_range("Figure index out of range (1-based indexing)");
        }
        return *figures_[index - 1];
    }

    /// Get number of figures in collection
    [[nodiscard]] std::size_t size() const { return figures_.size(); }

    /// Check if collection is empty
    [[nodiscard]] bool empty() const { return figures_.empty(); }

    /// Clear all figures
    void clear() { figures_.clear(); }

private:
    std::vector<std::unique_ptr<Figure>> figures_;
};

} // namespace geometry

#endif // GEOMETRY_COLLECTION_HPP
