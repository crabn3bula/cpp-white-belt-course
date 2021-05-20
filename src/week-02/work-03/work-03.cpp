#include <string>
#include <vector>

bool IsPalindrom(std::string word) {
    for (int i = 0; i <= word.size() / 2; ++i) {
        if (word[i] != word[word.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength) {
    std::vector<std::string> filtered_words;
    for (auto word : words) {
        if (word.length() >= minLength && IsPalindrom(word)) {
            filtered_words.push_back(word);
        }
    }
    return filtered_words;
}

int main() {
    auto test = PalindromFilter({ "abacaba", "aba" }, 5);
    test = PalindromFilter({ "abacaba", "aba" }, 2);
    test = PalindromFilter({ "weew", "bro", "code" }, 4);
    return 0;
}
