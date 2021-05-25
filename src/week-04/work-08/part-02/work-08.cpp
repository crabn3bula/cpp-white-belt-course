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

    int GetAdditionalFactor(int common_denominator) const {
        return common_denominator / m_denominator * m_numerator;
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

int main() {
    // first part tests
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            std::cout << "Rational(3, 10) != 3/10" << std::endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            std::cout << "Rational(8, 12) != 2/3" << std::endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            std::cout << "Rational(-4, 6) != -2/3" << std::endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            std::cout << "Rational(4, -6) != -2/3" << std::endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            std::cout << "Rational(0, 15) != 0/1" << std::endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            std::cout << "Rational() != 0/1" << std::endl;
            return 5;
        }
    }

    // second part tests 
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            std::cout << "4/6 != 2/3" << std::endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            std::cout << "2/3 + 4/3 != 2" << std::endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            std::cout << "5/7 - 2/9 != 31/63" << std::endl;
            return 3;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}
