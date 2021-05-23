#include <iostream>
#include <vector>
#include <algorithm>

class SortedStrings {
public:
    void AddString(const std::string& s) {
        unordered_strings.push_back(s);
    }
    std::vector<std::string> GetSortedStrings() {
        auto result = unordered_strings;
        std::sort(result.begin(), result.end());
        return result;
    }
private:
    std::vector<std::string> unordered_strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const std::string& s : strings.GetSortedStrings()) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
