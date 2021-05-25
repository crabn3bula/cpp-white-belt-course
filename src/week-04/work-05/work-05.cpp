#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream file("input.txt");

    std::string line;
    if (file) {
        std::cout << std::fixed;
        while(std::getline(file, line)) {
            std::cout << std::setprecision(3) << std::stof(line) << std::endl;
        }
    }
    return 0;
}
