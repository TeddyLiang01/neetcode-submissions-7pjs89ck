class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList; // source -> vector of <des, price>
        for (auto& flight : flights) {
            if (adjList.count(flight[0]) == 0) adjList[flight[0]] = {};
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<int> cost = vector<int>(n, INT_MAX);
        cost[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> tempCost = cost;
            for (int node = 0; node < n; ++node) {
                if (cost[node] == INT_MAX) continue;

                for (auto &p : adjList[node]) {
                    int destination = p.first;
                    int price = p.second;
                    tempCost[destination] = min(cost[node] + price, tempCost[destination]);
                }
            }
            cost = tempCost;
        }
        if (cost[dst] == INT_MAX) return -1;
        return cost[dst];

        
    }
};
