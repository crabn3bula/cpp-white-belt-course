#include <vector>
#include <algorithm>

class FunctionPart {
public:
    FunctionPart(char new_operand, double new_value) {
        operand = new_operand;
        value = new_value;
    }
    double Apply(double source_value) const {
        if (operand == '+') {
            return source_value + value;
        }

        if (operand == '-') {
            return source_value - value;
        }

        return source_value;
    }
    void Invert() {
        if (operand == '-') {
            operand = '+';
            return;
        }

        if (operand == '+') {
            operand = '-';
            return;
        }
    }
private:
    char operand;
    double value;
};

class Function {
public:
    void AddPart(char operand, double value) {
        parts.push_back({ operand, value });
    }
    double Apply(double value) const {
        for (const auto& part: parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (auto& part: parts) {
            part.Invert();
        }
        std::reverse(std::begin(parts), std::end(parts));
    }
private:
    std::vector<FunctionPart> parts;
};