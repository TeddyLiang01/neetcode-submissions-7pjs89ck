class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](auto& a, auto& b) {
            return a.first < b.first;
        });

        vector<double> timeToDest;
        for (int i = 0; i < cars.size(); ++i) {
            int dist = target - cars[i].first;
            double time = (double)dist / cars[i].second;
            timeToDest.push_back(time);
        }

        int groups = 0;
        double minTime = 0;
        for (int i = cars.size() - 1; i >= 0; --i) {
            if (timeToDest[i] > minTime) {
                groups++;
                minTime = timeToDest[i];
            }
        }
        return groups;
    }
};
