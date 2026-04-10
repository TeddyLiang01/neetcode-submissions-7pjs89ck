class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return 0;
        if (grid[y][x] == 0 || visited[y][x] == 1) return 0;
        visited[y][x] = 1;
        return 1 + bfs(grid, visited, x + 1, y) + bfs(grid, visited, x - 1, y) + bfs(grid, visited, x, y + 1) + bfs(grid, visited, x, y - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {    
        int max = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                int area = bfs(grid, visited, x, y);
                if (area > max) max = area;
            }
        }
        return max;
    }
};
