#include <vector>
#include <iostream>

int main() {
    int days_count;
    std::cin >> days_count;
    std::vector<int> temperatures(days_count);

    int sum = 0;
    for (int i = 0; i < days_count; ++i) {
        std::cin >> temperatures[i];
        sum += temperatures[i];
    }

    const int average = sum / temperatures.size();

    std::vector<int> indexes;
    for (auto i = 0; i < days_count; ++i) {
        if (temperatures[i] > average) {
            indexes.push_back(i);
        }
    }

    std::cout << indexes.size() << std::endl;
    for (const auto& index : indexes) {
        std::cout << index << " ";
    }
    return 0;
}