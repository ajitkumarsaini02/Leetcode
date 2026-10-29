class UndergroundSystem {
    unordered_map<int, pair<string, int>> check;
    unordered_map<string, pair<double, int>> route;

public:
    UndergroundSystem() {
        
    }

    void checkIn(int id, string stationName, int t) {
        check[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = check[id];

        string routeKey = startStation + "->" + stationName;
        int duration = t - startTime;

        route[routeKey].first += duration;
        route[routeKey].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string routeKey = startStation + "->" + endStation;
        auto& [totalTime, count] = route[routeKey];
        return totalTime / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */