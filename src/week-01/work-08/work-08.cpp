#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;

    // Euclidean algorithm
    int dividend = std::max(a, b);
    int divider = std::min(a, b);
    int remainder = dividend % divider;

    while (remainder != 0) {
        dividend = divider;
        divider = remainder;
        remainder = dividend % divider;
    }

    std::cout << divider;

    return 0;
}