#include <iostream>
#include <numeric>

class Rational {
public:
    Rational() {
        m_numerator = 0;
        m_denominator = 1;
    }

    Rational(const int numerator, const int denominator) {
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

    void SetNumerator(const int numerator) {
        m_numerator = numerator;
    }

    void SetDenominator(const int denominator) {
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

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return lhs * rhs.GetInversion();
}

int main() {
    {
        Rational a(-2, 3);
        Rational b(4, -3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            std::cout << "2/3 * 4/3 != 8/9" << std::endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            std::cout << "5/4 / 15/8 != 2/3" << std::endl;
            return 2;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}
