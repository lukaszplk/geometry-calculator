# geometry-calculator

Calculate perimeter and area of geometric figures using polymorphism.

## Supported Shapes

| Shape | Code | Parameters | Perimeter | Area |
|-------|------|------------|-----------|------|
| Circle | `c` | radius | 2πr | πr² |
| Square | `s` | side | 4s | s² |
| Rectangle | `r` | width, height | 2(w+h) | w×h |
| Triangle | `t` | a, b, c (sides) | a+b+c | Heron's formula |

## Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Requires C++20 (for `std::numbers::pi`).

## Usage

```bash
./geometry_calculator < input.txt
```

### Input Format

```
<number_of_figures>
<figure_type> <params...>
...
<number_of_queries>
<query_type> <figure_index>
...
```

### Query Types

- `p <index>` - Calculate perimeter (1-based index)
- `a <index>` - Calculate area (1-based index)

## Example

```
4
c 5
s 4
r 3 7
t 3 4 5
6
p 1
a 1
p 2
a 2
p 3
a 4
```

Output:
```
31.42
78.54
16.00
16.00
20.00
6.00
```

## Project Structure

```
geometry-calculator/
├── CMakeLists.txt
├── include/geometry/
│   ├── figure.hpp       # Abstract base class
│   ├── shapes.hpp       # Circle, Square, Rectangle, Triangle
│   ├── factory.hpp      # FigureFactory
│   └── collection.hpp   # FigureCollection
├── src/main.cpp
└── examples/input.txt
```

## License

See [LICENSE](LICENSE) file.
