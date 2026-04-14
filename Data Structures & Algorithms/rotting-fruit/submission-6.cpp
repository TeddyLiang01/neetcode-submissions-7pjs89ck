class Solution {
public:
    bool freshExists(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) return true;
            }
        }
        return false;
    }
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        int minutes = -1;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                pair<int, int> cord = q.front();
                q.pop();

                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto &dir : directions) {
                    int newRow = cord.first + dir.first;
                    int newCol = cord.second + dir.second;

                    if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()) continue;
                    if (grid[newRow][newCol] == 1) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 2;
                    }
                }
            }
            minutes++;
        }
        return minutes;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q; // row, col

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 2) q.push({row, col});
            }
        }
        
        int minutes = 0;
        if (!q.empty()) minutes = bfs(grid, q);
        if (freshExists(grid)) return -1;
        return minutes;
    }
};
