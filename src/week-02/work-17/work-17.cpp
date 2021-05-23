#include <iostream>
#include <set>
#include <map>

int main() {
    int requests_count;
    std::cin >> requests_count;

    std::string request;
    std::map<std::string, std::set<std::string>> word_synonyms;
    for (auto i = 0; i < requests_count; ++i) {
        std::cin >> request;

        if (request == "ADD") {
            std::string first_word, second_word;
            std::cin >> first_word >> second_word;
            word_synonyms[first_word].insert(second_word);
            word_synonyms[second_word].insert(first_word);
        } else if (request == "COUNT") {
            std::string word;
            std::cin >> word;
            std::cout << word_synonyms[word].size() << std::endl;;
        } else if (request == "CHECK") {
            std::string first_word, second_word;
            std::cin >> first_word >> second_word;
            if (word_synonyms[first_word].count(second_word) || word_synonyms[second_word].count(first_word)) {
                std::cout << "YES";
            } else {
                std::cout << "NO";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
