#include <iostream>
#include <set>
#include <map>

int main()
{
    int requests_count;
    std::cin >> requests_count;

    int stops_count;
    std::string stop;

    std::map<std::set<std::string>, int> routes;
    for (auto i = 0; i < requests_count; ++i) {
        std::cin >> stops_count;

        std::set<std::string> stops;
        for (auto j = 0; j < stops_count; ++j) {
            std::cin >> stop;
            stops.insert(stop);
        }

        if (routes.count(stops)) {
            std::cout << "Already exists for " << routes[stops] << std::endl;
        } else {
            const int route_id = routes.size() + 1;
            routes[stops] = route_id;
            std::cout << "New bus " << route_id << std::endl;
        }
    }
    return 0;
}
