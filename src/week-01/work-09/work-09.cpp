#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    const auto divider = 2;
    std::vector<int> bits;

    while (n >= divider) {
        bits.push_back(n % divider);
        n /= divider;
    }
    // push last bit
    bits.push_back(n);

    for (int i = bits.size() - 1; i >= 0; --i) {
        std::cout << bits[i];
    }
    std::cout << std::endl << 1 % 5;
    return 0;
}
