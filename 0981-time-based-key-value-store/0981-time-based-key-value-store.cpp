class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
        
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        auto& arr = mp[key];
        int i = 0;
        int j = arr.size() - 1;
        string ans = "";
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */