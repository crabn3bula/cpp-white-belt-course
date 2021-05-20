#include <iostream>
#include <vector>

void Swap(int& a, int& b) {
    const int tmp = b;
    b = a;
    a = tmp;
}

void Reverse(std::vector<int>& v) {
    for (int i = 0; i < v.size() / 2; ++i) {
        Swap(v[i], v[v.size() - i - 1]);
    }
}

int main() {
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    Reverse(nums);
    for (auto num : nums) {
        std::cout << num << " ";
    }
    return 0;
}