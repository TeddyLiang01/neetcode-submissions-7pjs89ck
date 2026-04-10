class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 1 && edges.size() == 0) return true;
        unordered_map<int, unordered_set<int>> adjacencyList;
        for (vector<int> &edge : edges) {
            if (edge[0] == edge[1]) return false;
            adjacencyList[edge[0]].insert(edge[1]);
            adjacencyList[edge[1]].insert(edge[0]);
        }

        if (adjacencyList.size() < n) return false;

        queue<int> toVisit;
        unordered_set<int> visited;
        toVisit.push(0);

        while (!toVisit.empty()) {
            int curNode = toVisit.front();
            if (visited.count(curNode) > 0) return false;
            visited.insert(curNode);
            for (int node : adjacencyList[curNode]) {
                if (visited.count(node) == 0) toVisit.push(node);
            }
            toVisit.pop();
        }

        if (visited.size() == n) return true;
        return false;
    }
};
