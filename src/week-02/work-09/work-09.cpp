#include <vector>
#include <iostream>
#include <string>

const auto is_worried = true;

void print_worried_count(const std::vector<int>& queue) {
    auto worried_count = 0;
    for (const auto& p : queue) {
        if (p == is_worried) {
            worried_count++;
        }
    }
    std::cout << worried_count << std::endl;
}

void enqueue(std::vector<int>& queue, const int count) {
    for (auto i = 0; i < count; ++i) {
        queue.push_back(0);
    }
}

void dequeue(std::vector<int>& queue, const int count) {
    for (auto i = 0; i < count; ++i) {
        queue.pop_back();
    }
}

void execute_next_command(std::vector<int>& queue) {
    std::string command;
    int param;

    std::cin >> command;
    if (command == "WORRY_COUNT") {
        print_worried_count(queue);
    }
    else {
        std::cin >> param;

        if (command == "WORRY") {
            queue[param] = is_worried;
        }
        else if (command == "QUIET") {
            queue[param] = !is_worried;
        }
        else if (command == "COME") {
            if (param > 0) {
                enqueue(queue, param);
            }
            else {
                dequeue(queue, param * -1);
            }
        }
    }
}

int main() {
    int op_count;
    std::vector<int> queue;

    std::cin >> op_count;
    for (auto i = 0; i < op_count; ++i) {
        execute_next_command(queue);
    }

    return 0;
}