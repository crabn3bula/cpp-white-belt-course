#include <iostream>
#include <vector>
#include <string>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination) {
    for (auto item : source) {
        destination.push_back(item);
    }
    source.clear();
}

int main() {
    std::vector<std::string> source = { "a", "b", "c" };
    std::vector<std::string> destination = { "z" };
    MoveStrings(source, destination);

    for (auto item : destination){
        std::cout << item << " ";
    }
    return 0;
}