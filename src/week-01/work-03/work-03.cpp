#include <iostream>
#include <cmath>

int main() {
	double a, b, c;
	std::cin >> a >> b >> c;

	if (a == .0 && b == .0) {
		return 0;
	}

	if (a == .0) {
	    std::cout << -c / b;
	    return 0;
	}

	auto const discriminant = std::pow(b, 2)- (4 * a * c);
	if (discriminant > 0) {
	    std::cout << (-b + std::sqrt(discriminant)) / (2 * a) << " ";
		std::cout << (-b - std::sqrt(discriminant)) / (2 * a);
		return 0;
	}

	if (discriminant == .0) {
	    std::cout << -b / (2 * a);
		return 0;
	}

	return 0;
}
