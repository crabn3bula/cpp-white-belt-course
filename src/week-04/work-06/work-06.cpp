#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream file("input.txt");

    if (file) {
        int rows, cols = 0;
        file >> rows;
        file.ignore(1);
        file >> cols;

        int cell_value;
        std::cout << std::setfill(' ');
        for (auto i = 1; i <= rows; ++i) {
            for (auto j = 1; j <= cols; ++j) {
                file >> cell_value;
                // ignore delimiter
                file.ignore(1);
                std::cout << std::setw(10);
                std::cout << cell_value;
                // space delimiter between cells except last value in the row
                if (j < cols) {
                    std::cout << " ";
                }
            }
            // last row without end line character
            if (i < rows) {
                std::cout << std::endl;
            }
        }
    }
    return 0;
}
