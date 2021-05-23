#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        firstname_history[year] = first_name;
    }

    void ChangeLastName(int year, const std::string& last_name) {
        lastname_history[year] = last_name;
    }

    std::string GetFullName(int year) {
        const auto nearest_firstname_year = FindNearestYear(firstname_history, year);
        const auto nearest_lastname_year = FindNearestYear(lastname_history, year);

        const bool is_firstname_changed = firstname_history.count(nearest_firstname_year);
        const bool is_lastname_changed = lastname_history.count(nearest_lastname_year);

        std::string fullname = "Incognito";

        if (!is_firstname_changed && is_lastname_changed) {
            fullname = lastname_history[nearest_lastname_year] + " with unknown first name";
        }

        if (is_firstname_changed && !is_lastname_changed) {
            fullname = firstname_history[nearest_firstname_year] + " with unknown last name";
        }

        if (is_firstname_changed && is_lastname_changed) {
            fullname = firstname_history[nearest_firstname_year] + " " + lastname_history[nearest_lastname_year];
        }
        return fullname;
    }
private:
    std::map<int, std::string> firstname_history;
    std::map<int, std::string> lastname_history;
    int FindNearestYear(const std::map<int, std::string>& history, const int& threshold) {
        std::vector<int> years;
        for (const auto& entry : history) {
            years.push_back(entry.first);
        }

        std::sort(std::begin(years), std::end(years), [](const int& l, const int& r) {
            return r < l;
        });

        auto nearest_year = threshold;
        for (const auto& year : years) {
            if (year <= threshold) {
                nearest_year = year;
                break;
            }
        }

        return nearest_year;
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    return 0;
}
