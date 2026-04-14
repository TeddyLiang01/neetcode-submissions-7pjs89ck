class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        unordered_set<int> toBeProcessed;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            unordered_set<int> processing = toBeProcessed;
            for (auto &index : toBeProcessed) {
                if (temperatures[index] < temperatures[i]) {
                    res[index] = i - index;
                    processing.erase(index);
                }
            }
            processing.insert(i);
            toBeProcessed = processing;
        }
        return res;
    }
};
