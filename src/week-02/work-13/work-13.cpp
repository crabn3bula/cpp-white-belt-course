#include <iostream>
#include <map>
#include <vector>

void new_bus(std::map<std::string, std::vector<std::string>>& buses_with_stops, std::map<std::string, std::vector<std::string>>& stops_with_buses) {
    std::string bus;
    int stop_count;
    std::cin >> bus >> stop_count;

    std::string stop;
    for (auto i = 0; i < stop_count; ++i) {
        std::cin >> stop;
        buses_with_stops[bus].push_back(stop);
        stops_with_buses[stop].push_back(bus);
    }
}

void buses_for_stop(std::map<std::string, std::vector<std::string>>& stops_with_buses) {
    std::string stop;
    std::cin >> stop;

    if (!stops_with_buses.count(stop)) {
        std::cout << "No stop" << std::endl;
        return;
    }

    for (const auto& bus : stops_with_buses[stop]) {
        std::cout << bus << " ";
    }
    std::cout << std::endl;
}

bool is_interchange(const std::vector<std::string>& buses, const std::string& bus) {
    for (const auto& b: buses) {
        if (b != bus) {
            return true;
        }
    }
    return false;
}

void stops_for_bus(std::map<std::string, std::vector<std::string>>& buses_with_stops, std::map<std::string, std::vector<std::string>>& stops_with_buses) {
    std::string bus;
    std::cin >> bus;

    if (!buses_with_stops.count(bus)) {
        std::cout << "No bus" << std::endl;
        return;
    }

    for (const auto& stop : buses_with_stops[bus]) {
        std::cout << "Stop " << stop << ": ";

        if (!stops_with_buses.count(stop) || !is_interchange(stops_with_buses[stop], bus)) {
            std::cout << "no interchange";
        } else {
            for (const auto& stop_bus : stops_with_buses[stop]) {
                if (bus != stop_bus)
                {
                    std::cout << stop_bus << " ";
                }
            }
        }
        
        std::cout << std::endl;
    }
}

void all_buses(const std::map<std::string, std::vector<std::string>>& buses_with_stops) {
    if (buses_with_stops.empty()) {
        std::cout << "No buses" << std::endl;
        return;
    }

    for (const auto& bus : buses_with_stops) {
        std::cout << "Bus " << bus.first << ": ";

        for (const auto& stop_bus : bus.second) {
            std::cout << stop_bus << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    int commands_count;
    std::cin >> commands_count;

    std::string command;

    std::map<std::string, std::vector<std::string>> buses_with_stops;
    std::map<std::string, std::vector<std::string>> stops_with_buses;
    for (auto i = 0; i < commands_count; ++i) {
        std::cin >> command;

        if (command == "NEW_BUS") {
            new_bus(buses_with_stops, stops_with_buses);
        } else if (command == "BUSES_FOR_STOP") {
            buses_for_stop(stops_with_buses);
        } else if (command == "STOPS_FOR_BUS") {
            stops_for_bus(buses_with_stops, stops_with_buses);
        } else if (command == "ALL_BUSES") {
            all_buses(buses_with_stops);
        }
    }
    return 0;
}
