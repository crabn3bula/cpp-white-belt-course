#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    int args_count;
    std::cin >> args_count;

    int num;
    std::vector<int> numbers;
    for (auto i = 0; i < args_count; ++i) {
        std::cin >> num;
        numbers.push_back(num);
    }

    std::sort(numbers.begin(), numbers.end(), [](int x, int y) {
        return std::abs(x) < std::abs(y);
    });

    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
