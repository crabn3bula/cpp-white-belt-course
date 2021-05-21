#include <iostream>
#include <vector>
#include <string>

void switch_month(std::vector<std::vector<std::string>>& days_with_tasks, int new_days_count) {
    // just resize if without loss of tasks
    if (days_with_tasks.size() <= new_days_count) {
        days_with_tasks.resize(new_days_count);
        return;
    }

    // shift tasks from invalid days to last day of new month
    std::vector<std::string> shifted_tasks;
    for (auto i = new_days_count; i < days_with_tasks.size(); ++i) {
        shifted_tasks.insert(shifted_tasks.end(), days_with_tasks[i].begin(), days_with_tasks[i].end());
    }

    const auto from_date = new_days_count - 1;
    days_with_tasks.resize(new_days_count);
    days_with_tasks[from_date].insert(days_with_tasks[from_date].end(), shifted_tasks.begin(), shifted_tasks.end());
}

int increment_month_index(int current_index) {
    if (current_index == 11) {
        return 0;
    }

    return ++current_index;
}

int main() {
    int commands_count;
    std::cin >> commands_count;

    auto current_month_index = 0;
    const std::vector<int> days_in_months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    std::vector<std::vector<std::string>> days_with_tasks(days_in_months[current_month_index]);

    for (auto i = 0; i < commands_count; ++i) {
        std::string command;
        int day;
        std::cin >> command;

        if (command == "ADD") {
            std::string task;
            std::cin >> day >> task;

            days_with_tasks[day - 1].push_back(task);
        }
        else if (command == "NEXT") {
            current_month_index = increment_month_index(current_month_index);
            switch_month(days_with_tasks, days_in_months[current_month_index]);
        }
        else if (command == "DUMP") {
            std::cin >> day;
            const auto day_index = day - 1;
            std::cout << days_with_tasks[day_index].size() << " ";
            for (const auto& task : days_with_tasks[day_index]) {
                std::cout << task << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}