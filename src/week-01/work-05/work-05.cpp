#include <iostream>

int main() {
    double price_n, limit_a, limit_b, discount_x, discount_y;
    std::cin >> price_n >> limit_a >> limit_b >> discount_x >> discount_y;

    // According to the description of the task, A is less than B, so first we check B
    if (price_n > limit_b) {
        std::cout << price_n - (price_n / 100.0 * discount_y);
        return 0;
    }

    if (price_n > limit_a) {
        std::cout << price_n - (price_n / 100.0 * discount_x);
        return 0;
    }

    std::cout << price_n;

    return 0;
}
