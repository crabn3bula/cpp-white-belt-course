#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    if (file) {
        while (std::getline(file, line))  {
            std::cout << line << std::endl;
        }
    }
    return 0;
}
