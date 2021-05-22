#include <iostream>
#include <map>

void change_capital(std::map<std::string, std::string>& countries) {
    std::string country, new_capital;
    std::cin >> country >> new_capital;

    // country is not existed
    if (!countries.count(country)) {
        std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
    } else if (countries[country] != new_capital) {
        std::cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital << std::endl;
    } else {
        std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
    }
    countries[country] = new_capital;
}

void rename(std::map<std::string, std::string>& countries) {
    std::string old_name, new_name;
    std::cin >> old_name >> new_name;

    if (old_name == new_name || !countries.count(old_name) || countries.count(new_name)) {
        std::cout << "Incorrect rename, skip" << std::endl;
        return;
    }

    const auto capital = countries[old_name];
    countries.erase(old_name);
    countries[new_name] = capital;
    std::cout << "Country " << old_name << " with capital " << capital << " has been renamed to " << new_name << std::endl;
}

void about(std::map<std::string, std::string>& countries) {
    std::string country;
    std::cin >> country;

    if (!countries.count(country)) {
        std::cout << "Country " << country << " doesn't exist" << std::endl;
        return;
    }

    std::cout << "Country " << country << " has capital " << countries[country] << std::endl;
}

void dump(std::map<std::string, std::string>& countries) {
    if (countries.empty()) {
        std::cout << "There are no countries in the world" << std::endl;
        return;
    }

    for (const auto& country : countries) {
        std::cout << country.first << "/" << country.second << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int command_count;
    std::cin >> command_count;

    std::string command;
    std::map<std::string, std::string> countries;
    for (auto i = 0; i < command_count; ++i) {
        std::cin >> command;
        
        if (command == "CHANGE_CAPITAL") {
            change_capital(countries);
        } else if (command == "RENAME") {
            rename(countries);
        } else if (command == "ABOUT") {
            about(countries);
        } else if (command == "DUMP") {
            dump(countries);
        }
    }
    return 0;
}
