#include <geometry/collection.hpp>
#include <geometry/factory.hpp>

#include <iomanip>
#include <iostream>

void processQuery(char queryType, std::size_t index, const geometry::FigureCollection& figures) {
    const auto& figure = figures.get(index);
    
    std::cout << std::fixed << std::setprecision(2);
    
    switch (queryType) {
        case 'p': case 'P':
            std::cout << figure.perimeter() << '\n';
            break;
        case 'a': case 'A':
            std::cout << figure.area() << '\n';
            break;
        default:
            std::cerr << "Unknown query type: '" << queryType << "'\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        geometry::FigureCollection figures;

        // Read figures
        std::cout << "Number of figures: ";
        int numFigures;
        std::cin >> numFigures;

        for (int i = 0; i < numFigures; ++i) {
            char figureType;
            std::cin >> figureType;
            figures.add(geometry::FigureFactory::create(figureType, std::cin));
        }

        // Process queries
        int numQueries;
        std::cin >> numQueries;

        for (int i = 0; i < numQueries; ++i) {
            char queryType;
            std::size_t index;
            std::cin >> queryType >> index;
            processQuery(queryType, index, figures);
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
