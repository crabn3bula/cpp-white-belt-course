#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string firstName;
    std::string lastName;
    int day;
    int month;
    int year;
};

void print_full_name(const Student& s) {
    std::cout << s.firstName << " " << s.lastName << std::endl;
}

void print_date_of_birth(const Student& s) {
    std::cout << s.day << '.' << s.month << '.' << s.year << std::endl;
} 

int main() {
    int students_count;
    std::cin >> students_count;

    std::vector<Student> students(students_count);
    for (auto i = 0; i < students_count; ++i) {
        Student s;
        std::cin >> s.firstName >> s.lastName >> s.day >> s.month >> s.year;

        students[i] = s;
    }

    int requests_count;
    std::cin >> requests_count;

    std::string request;
    int student_id;
    for (auto i = 0; i < requests_count; ++i) {
        std::cin >> request >> student_id;

        if (student_id > students_count || student_id < 1 || (request != "name"  && request != "date")) {
            std::cout << "bad request" << std::endl;
            continue;
        }

        if (request == "name") {
            print_full_name(students[student_id - 1]);
        } else if (request == "date") {
            print_date_of_birth(students[student_id - 1]);
        }
    }

    return 0;
}
