#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <vector>

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
private:
    int m_numerator;
    int m_denominator;

    void SetNumerator(int numerator) {
        m_numerator = numerator;
    }

    void SetDenominator(int denominator) {
        if (m_numerator == 0) {
            m_denominator = 1;
        } else {
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

bool operator<(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return lhs.Numerator() < rhs.Numerator();
    }

    const auto common_denominator = lhs.CommonDenominator(rhs);
    return lhs.GetAdditionalFactor(common_denominator) < rhs.GetAdditionalFactor(common_denominator);
}

int main() {
    {
        const std::set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            std::cout << "Wrong amount of items in the set" << std::endl;
            return 1;
        }

        std::vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != std::vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            std::cout << "Rationals comparison works incorrectly" << std::endl;
            return 2;
        }
    }

    {
        std::map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            std::cout << "Wrong amount of items in the map" << std::endl;
            return 3;
        }
    }


    std::cout << "OK" << std::endl;
    return 0;
}
