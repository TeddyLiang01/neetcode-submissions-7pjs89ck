class Solution {
public:
    bool process(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return false;
        if (grid[row][col] == -1 || grid[row][col] == 0) return false;
        if (visited[row][col] == true) return false;
        visited[row][col] = true;
        return true;
    }
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        queue<pair<int, int>> toVisit;
        toVisit.push({row, col});
        visited[row][col] = true;
        int distance = 0;
        while (!toVisit.empty()) {
            distance++;
            int layer = toVisit.size();
            for (int i = 0; i < layer; ++i) {
                pair<int, int> point = toVisit.front();
                toVisit.pop();
                vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                for (auto &dir : directions) {
                    if (process(grid, visited, point.first + dir.first, point.second + dir.second)) {
                        grid[point.first + dir.first][point.second + dir.second] = min(distance, grid[point.first + dir.first][point.second + dir.second]);
                        toVisit.push({point.first + dir.first, point.second + dir.second});
                    }   
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
                if (!visited[row][col] && grid[row][col] == 0) bfs(grid, visited, row, col);
            }
        }
    }
};
