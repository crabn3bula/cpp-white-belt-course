#include <fstream>
#include <string>

int main() {
    std::ifstream ifile("input.txt");
    std::string line;
    if (ifile) {
        std::ofstream ofile("output.txt");
        while (std::getline(ifile, line)) {
            ofile << line << std::endl;
        }
    }
    return 0;
}
