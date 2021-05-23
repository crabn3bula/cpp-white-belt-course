#include <iostream>
#include <map>
#include <vector>

int main()
{
    int routes_count;
    std::cin >> routes_count;

    int stops_count;

    std::map<std::vector<std::string>, int> routes;
    for (auto i = 0; i < routes_count; ++i) {
        std::string stop_name;
        std::cin >> stops_count;
        std::vector<std::string> stops(stops_count);

        for (auto j = 0; j < stops_count; ++j) {
            std::cin >> stop_name;
            stops[j] = stop_name;
        }

        if (!routes.count(stops)) {
            const auto route_id = routes.size() + 1;
            routes[stops] = route_id;
            std::cout << "New bus " << route_id << std::endl;
        } else {
            std::cout << "Already exists for " << routes[stops] << std::endl;
        }
    }
    return 0;
}
