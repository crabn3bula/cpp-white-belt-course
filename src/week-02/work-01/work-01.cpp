#include <iostream>

int Factorial(int number) {
    int result = 1;
    if (number <= 1) {
        return result;
    }

    for (int i = 1; i <= number; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    int a;
    std::cin >> a;

    std::cout << Factorial(a);
    return 0;
}
