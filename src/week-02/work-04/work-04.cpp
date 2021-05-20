#include <iostream>

void UpdateIfGreater(int a, int& b) {
    if (a > b) {
        b = a;
    }
}

int main() {
    auto a = 2;
    auto b = 1;
    UpdateIfGreater(a, b);
    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

    UpdateIfGreater(2, b);
    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

    return 0;
}
