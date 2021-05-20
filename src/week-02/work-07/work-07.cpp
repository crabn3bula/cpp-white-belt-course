#include <iostream>
#include <vector>

std::vector<int> Reversed(const std::vector<int>& v) {
    std::vector<int> reversed;
    for (int i = v.size() - 1; i >= 0; --i) {
        reversed.push_back(v[i]);
    }
    return reversed;
}

int main() {
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    for (auto num : Reversed(nums)) {
        std::cout << num << " ";
    }
    return 0;
}