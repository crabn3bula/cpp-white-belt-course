#include <iostream>
#include <set>

int main() {
    int words_count;
    std::cin >> words_count;

    std::string word;
    std::set<std::string> unique_words;
    for (auto i = 0; i < words_count; ++i) {
        std::cin >> word;
        unique_words.insert(word);
    }

    std::cout << unique_words.size();
    return 0;
}
