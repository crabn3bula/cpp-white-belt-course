#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
    std::string a, b, c;
    std::cin >> a >> b >> c;

    std::vector<std::string> words = { a, b, c };
    std::sort(std::begin(words), std::end(words));
    std::cout << words[0];

    return 0;
}
