#include <iostream>
#include <algorithm>
#include <vector>

std::string string_to_lower(const std::string& s) {
    std::string lowered_string;
    for (auto& c : s) {
        lowered_string.push_back(std::tolower(c));
    }
    return lowered_string;
}

int main() {
    int words_count;
    std::cin >> words_count;

    std::string word;
    std::vector<std::string> words;
    for (auto i = 0; i < words_count; ++i) {
        std::cin >> word;
        words.push_back(word);
    }

    std::sort(words.begin(), words.end(), [](const std::string& l, const std::string& r) {
        return string_to_lower(l) < string_to_lower(r);
    });

    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
    return 0;
}
