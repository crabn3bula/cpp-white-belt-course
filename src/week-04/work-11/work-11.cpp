#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>

class Rational {
public:
    Rational() {
        m_numerator = 0;
        m_denominator = 1;
    }

    Rational(const int numerator, const int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Invalid argument");
        }
        m_numerator = numerator;
        m_denominator = denominator;
        Recompute();
    }

    int Numerator() const {
        return m_numerator;
    }

    int Denominator() const {
        return m_denominator;
    }

    int CommonDenominator(const Rational& r) const {
        return m_denominator * r.m_denominator;
    }

    int GetAdditionalFactor(const int common_denominator) const {
        return common_denominator / m_denominator * m_numerator;
    }

    Rational GetInversion() const {
        return Rational(m_denominator, m_numerator);
    }
private:
    int m_numerator;
    int m_denominator;

    void SetNumerator(int numerator) {
        m_numerator = numerator;
    }

    void SetDenominator(int denominator) {
        if (m_numerator == 0) {
            m_denominator = 1;
        }
        else {
            m_denominator = denominator;
        }
    }

    void Recompute() {
        const auto gcd = std::gcd(m_numerator, m_denominator);
        const auto sign = (m_numerator >= 0) && (m_denominator >= 0) || (m_numerator < 0) && (m_denominator < 0) ? 1 : -1;
        const auto updated_numerator = std::abs(m_numerator) / gcd * sign;
        const auto updated_denominator = std::abs(m_denominator) / gcd;
        SetNumerator(updated_numerator);
        SetDenominator(updated_denominator);
    }
};

Rational operator-(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
    }

    const auto common_denominator = lhs.CommonDenominator(rhs);
    const auto new_numerator = lhs.GetAdditionalFactor(common_denominator) - rhs.GetAdditionalFactor(common_denominator);

    return Rational(new_numerator, common_denominator);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
    }

    const auto common_denominator = lhs.CommonDenominator(rhs);
    const auto new_numerator = lhs.GetAdditionalFactor(common_denominator) + rhs.GetAdditionalFactor(common_denominator);
    return Rational(new_numerator, common_denominator);
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw std::domain_error("Division by zero");
    }
    return lhs * rhs.GetInversion();
}

std::ostream& operator<<(std::ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

std::istream& operator>>(std::istream& stream, Rational& r) {
    int s_numerator;
    int s_denominator;
    char s_delimiter;

    if (stream >> s_numerator && stream >> s_delimiter && stream >> s_denominator) {
        if (s_delimiter == '/') {
            r = Rational(s_numerator, s_denominator);
        }
    }

    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return lhs.Numerator() < rhs.Numerator();
    }

    const auto common_denominator = lhs.CommonDenominator(rhs);
    return lhs.GetAdditionalFactor(common_denominator) < rhs.GetAdditionalFactor(common_denominator);
}

int main() {
    Rational r1, r2;
    char operation;

    try {
        std::cin >> r1 >> operation >> r2;
        if (operation == '+') {
            std::cout << r1 + r2;
        }
        else if (operation == '-') {
            std::cout << r1 - r2;
        }
        else if (operation == '/') {
            std::cout << r1 / r2;
        }
        else if (operation == '*') {
            std::cout << r1 * r2;
        }
    } catch (std::exception& ex) {
        std::cout << ex.what();
    }
    

    return 0;
}
