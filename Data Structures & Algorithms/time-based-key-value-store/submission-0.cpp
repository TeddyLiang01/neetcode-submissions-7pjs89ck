class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back(make_pair(timestamp, value));
    }

    string binarySearch(vector<pair<int, string>> &logs, int &timestamp) {
        int l = 0;
        int r = logs.size() - 1;
        pair<int, string> res;
        bool hasRes = false;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (logs[mid].first <= timestamp) {
                if (!hasRes || res.first < logs[mid].first) res = logs[mid];
                hasRes = true;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (hasRes) return res.second;
        return "";
    }
    
    string get(string key, int timestamp) {
        return binarySearch(store[key], timestamp);
    }
};
