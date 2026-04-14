class Solution {
public:
    bool process(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return false;
        if (grid[row][col] != INT_MAX) return false;
        return true;
    }

    void bfs(queue<pair<int, int>> toVisit, vector<vector<int>>& grid) {
        int distance = 0;
        while (!toVisit.empty()) {
            distance++;
            int layer = toVisit.size();
            for (int i = 0; i < layer; ++i) {
                pair<int, int> point = toVisit.front();
                toVisit.pop();
                vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                for (auto &dir : directions) {
                    int row = point.first + dir.first;
                    int col = point.second + dir.second;
                    if (process(grid, row, col)) {
                        grid[row][col] = min(distance, grid[row][col]);
                        toVisit.push({row, col});
                    }   
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> toVisit;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
                if (!visited[row][col] && grid[row][col] == 0) toVisit.push({row, col});
            }
        }
        bfs(toVisit, grid);
    }
};
