#include <iostream>

bool IsPalindrom(std::string word) {
    for (int i = 0; i <= word.size() / 2; ++i) {
        if (word[i] != word[word.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string word;
    std::cin >> word;
    std::cout << IsPalindrom(word);
    return 0;
}
