class Solution {
public:
    void visitIsland(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        if (col - 1 >= 0 && grid[row][col - 1] == '1' && !visited[row][col - 1]) visitIsland(row, col - 1, grid, visited);
        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1' && !visited[row][col + 1]) visitIsland(row, col + 1, grid, visited);
        if (row - 1 >= 0 && grid[row - 1][col] == '1' && !visited[row - 1][col]) visitIsland(row - 1, col, grid, visited);
        if (row + 1 < grid.size() && grid[row + 1][col] == '1' && !visited[row + 1][col]) visitIsland(row + 1, col, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1' && visited[row][col] == false) {
                    visitIsland(row, col, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};
