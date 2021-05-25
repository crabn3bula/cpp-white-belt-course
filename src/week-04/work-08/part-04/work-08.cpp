#include <iostream>
#include <numeric>
#include <sstream>

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

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
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

int main() {
    {
        std::ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            std::cout << "Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
            return 1;
        }
    }

    {
        std::istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            std::cout << "5/7 is incorrectly read as " << r << std::endl;
            return 2;
        }
    }

    {
        std::istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            std::cout << "Read from empty stream works incorrectly" << std::endl;
            return 3;
        }
    }

    {
        std::istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
            return 5;
        }
    }

    {
        std::istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            std::cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                << r1 << " " << r2 << " " << r3 << std::endl;

            return 6;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}
