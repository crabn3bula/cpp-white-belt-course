#include <iostream>
#include <algorithm>

class ReversibleString {
public:
    ReversibleString(){}
    ReversibleString(const std::string& input_str) {
        str = input_str;
    }

    std::string ToString() const {
        return str;
    }

    void Reverse() {
        std::reverse(str.begin(), str.end());
    }
private:
    std::string str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    std::cout << s.ToString() << std::endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    std::string tmp = s_ref.ToString();
    std::cout << tmp << std::endl;

    ReversibleString empty;
    std::cout << '"' << empty.ToString() << '"' << std::endl;

    return 0;
}
