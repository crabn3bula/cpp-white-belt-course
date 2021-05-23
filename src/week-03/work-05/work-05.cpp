#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        firstname_history[year] = first_name;
    }

    void ChangeLastName(int year, const std::string& last_name) {
        lastname_history[year] = last_name;
    }

    std::string GetFullName(int year) {
        const auto first_name = FindNameByYear(firstname_history, year);
        const auto last_name = FindNameByYear(lastname_history, year);

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }

        if (first_name.empty()) {
            return last_name + " with unknown first name";
        }

        if (last_name.empty()) {
            return first_name + " with unknown last name";
        }

        return first_name + " " + last_name;
    }

    std::string GetFullNameWithHistory(int year) {
        const auto first_name = FindNameByYear(firstname_history, year);
        const auto last_name = FindNameByYear(lastname_history, year);

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }

        const auto firstname_h = GetNameHistory(firstname_history, year);
        const auto lastname_h = GetNameHistory(lastname_history, year);
        // dumb way to print with spaces
        if (first_name.empty()) {
            return last_name + (lastname_h.empty() ? " " : " " + lastname_h + " ") + "with unknown first name";
        }

        if (last_name.empty()) {
            return first_name + (firstname_h.empty() ? " " : " " + firstname_h + " ") + "with unknown last name";
        }

        return first_name + (firstname_h.empty() ? " " : " " + firstname_h + " ") + last_name + (lastname_h.empty() ? "" : " " + lastname_h);
    }
private:
    std::map<int, std::string> firstname_history;
    std::map<int, std::string> lastname_history;

    std::string FindNameByYear(const std::map<int, std::string>& history, int year) {
        std::string name;
        for (const auto& entry : history) {
            if (entry.first <= year) {
                name = entry.second;
            } else {
                break;
            }
        }
        return name;
    }

    std::string GetNameHistory(const std::map<int, std::string>& history, int year) {
        // dumb way
        std::string lastname;
        std::vector<std::string> names;
        for (const auto& entry : history) {
            if (entry.first <= year) {
                if (lastname != entry.second) {
                    names.push_back(entry.second);
                }
                lastname = entry.second;
            } else {
                
                break;
            }
        }

        if (names.size() <= 1) {
            return "";
        }

        names.pop_back();
        std::string names_str;
        for (int i = names.size() - 1; i >= 0; --i) {
            names_str += names[i];
            if (i != 0) {
                names_str += ", ";
            }
        }
        
        return "(" + names_str + ")";
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    std::cout << person.GetFullNameWithHistory(1990) << std::endl;

    person.ChangeFirstName(1966, "Pauline");
    std::cout << person.GetFullNameWithHistory(1966) << std::endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    std::cout << person.GetFullNameWithHistory(1967) << std::endl;

    return 0;
}
