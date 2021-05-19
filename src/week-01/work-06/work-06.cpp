#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    for (; a <= b; ++a) {
        if (a % 2 == 0) {
            std::cout << a << " ";
        }
    }

    return 0;
}
