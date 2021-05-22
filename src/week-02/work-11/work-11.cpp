#include <map>
#include <string>
#include <iostream>

std::map<char, int> build_char_counter(const std::string& word) {
    std::map<char, int> char_counter;
    for (const auto& c : word) {
        ++char_counter[c];
    }
    return char_counter;
}

int main() {
    int pairs_count;
    std::cin >> pairs_count;

    std::string first_word;
    std::string second_word;
    for (auto i = 0; i < pairs_count; ++i) {
        std::cin >> first_word >> second_word;

        const auto is_anagram = build_char_counter(first_word) == build_char_counter(second_word);
        std::cout << (is_anagram ? "YES" : "NO") << std::endl;
    }
}
