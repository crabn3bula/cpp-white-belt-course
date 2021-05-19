#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cin >> word;

    int position = -2;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == 'f') {
            position++;
        }

        // second occurrence
        if (position == 0) {
            position = i;
            break;
        }
    }

    std::cout << position;
    return 0;
}
