#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::string> FindNamesHistory(const std::map<int, std::string>& names_by_year,
    int year) {
    std::vector<std::string> names;
    // перебираем всю историю в хронологическом порядке
    for (const auto& item : names_by_year) {
        // если очередное имя не относится к будущему и отличается от предыдущего,
        if (item.first <= year && (names.empty() || names.back() != item.second)) {
            // добавляем его в историю
            names.push_back(item.second);
        }
    }
    return names;
}

std::string BuildJoinedName(std::vector<std::string> names) {
    // нет истории — имя неизвестно
    if (names.empty()) {
        return "";
    }
    // меняем прямой хронологический порядок на обратный
    std::reverse(std::begin(names), std::end(names));

    // начинаем строить полное имя с самого последнего
    std::string joined_name = names[0];

    // перебираем все последующие имена
    for (int i = 1; i < names.size(); ++i) {
        if (i == 1) {
            // если это первое «историческое» имя, отделяем его от последнего скобкой
            joined_name += " (";
        }
        else {
            // если это не первое имя, отделяем от предыдущего запятой
            joined_name += ", ";
        }
        // и добавляем очередное имя
        joined_name += names[i];
    }

    // если в истории было больше одного имени, мы открывали скобку — закроем её
    if (names.size() > 1) {
        joined_name += ")";
    }
    // имя со всей историей готово
    return joined_name;
}

// см. решение предыдущей задачи
std::string BuildFullName(const std::string& first_name, const std::string& last_name) {
    if (first_name.empty() && last_name.empty()) {
        return "Incognito";
    }
    else if (first_name.empty()) {
        return last_name + " with unknown first name";
    }
    else if (last_name.empty()) {
        return first_name + " with unknown last name";
    }
    else {
        return first_name + " " + last_name;
    }
}

class Person {
public:
    Person(const std::string& firstName, const std::string& lastName, int year) { 
        m_yearOfBirth = year;
        ChangeFirstName(year, firstName);
        ChangeLastName(year, lastName);
    }

    void ChangeFirstName(int year, const std::string& first_name) {
        if (year < m_yearOfBirth) {
            return;
        }
        m_firstName = first_name;
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        if (year < m_yearOfBirth) {
            return;
        }
        m_lastName = last_name;
        last_names[year] = last_name;
    }

    std::string GetFullName(int year) const {
        if(year < m_yearOfBirth) {
            return "No person";
        }
        // найдём историю изменений имени и фамилии
        // в данном случае это излишне, так как нам достаточно узнать последние имя и фамилию, но почему бы не использовать готовые функции?
        const std::vector<std::string> first_names_history = FindFirstNamesHistory(year);
        const std::vector<std::string> last_names_history = FindLastNamesHistory(year);

        // подготовим данные для функции BuildFullName: возьмём последние имя и фамилию или оставим их пустыми, если они неизвестны
        std::string first_name;
        std::string last_name;
        if (!first_names_history.empty()) {
            first_name = first_names_history.back();
        }
        if (!last_names_history.empty()) {
            last_name = last_names_history.back();
        }
        return BuildFullName(first_name, last_name);
    }

    std::string GetFullNameWithHistory(int year) const {
        if (year < m_yearOfBirth) {
            return "No person";
        }
        // получим полное имя со всей историей
        const std::string first_name = BuildJoinedName(FindFirstNamesHistory(year));
        // получим полную фамилию со всей историей
        const std::string last_name = BuildJoinedName(FindLastNamesHistory(year));
        // объединим их с помощью готовой функции
        return BuildFullName(first_name, last_name);
    }

private:
    std::vector<std::string> FindFirstNamesHistory(int year) const {
        return FindNamesHistory(first_names, year);
    }
    std::vector<std::string> FindLastNamesHistory(int year) const {
        return FindNamesHistory(last_names, year);
    }

    std::string m_firstName;
    std::string m_lastName;
    int m_yearOfBirth;
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    return 0;
}
