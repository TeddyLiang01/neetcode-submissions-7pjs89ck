class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int height = heights.size();
        const int width = heights[0].size();
        vector<vector<int>> pacificAccess(height, vector<int>(width));
        vector<vector<int>> atlanticAccess(height, vector<int>(width));
        for (int i = 0; i < height; ++i) {
            pacificAccess[i][0] = 1;
            atlanticAccess[i][width - 1] = 1;
        }

        for (int i = 0; i < width; ++i) {
            pacificAccess[0][i] = 1;
            atlanticAccess[height - 1][i] = 1;
        }

        vector<vector<int>> pacificVisited(height, vector<int>(width));
        vector<vector<int>> atlanticVisited(height, vector<int>(width));
        vector<vector<int>> result;

        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c) {
                if (hasAccess(heights, {r, c}, pacificAccess, pacificVisited, width, height) && hasAccess(heights, {r, c}, atlanticAccess, atlanticVisited, width, height)) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }

    bool hasAccess(vector<vector<int>>& heights, vector<int> point, vector<vector<int>> &access, vector<vector<int>> &visited, int width, int height) {
        if (visited[point[0]][point[1]] == 1) return false;
        if (access[point[0]][point[1]] == 1) return true;

        visited[point[0]][point[1]] = 1;

        if (point[0] < height - 1) {
            if (heights[point[0] + 1][point[1]] <= heights[point[0]][point[1]] && hasAccess(heights, {point[0] + 1, point[1]}, access, visited, width, height)) {
                visited[point[0]][point[1]] = 0;
                access[point[0]][point[1]] = 1;
                return true;
            }
        } 
        if (point[0] > 0) {
            if (heights[point[0] - 1][point[1]] <= heights[point[0]][point[1]] && hasAccess(heights, {point[0] - 1, point[1]}, access, visited, width, height)) {
                visited[point[0]][point[1]] = 0;
                access[point[0]][point[1]] = 1;
                return true;
            }
        }
        if (point[1] < width - 1) {
            if (heights[point[0]][point[1] + 1] <= heights[point[0]][point[1]] && hasAccess(heights, {point[0], point[1] + 1}, access, visited, width, height)) {
                visited[point[0]][point[1]] = 0;
                access[point[0]][point[1]] = 1;
                return true;
            }
        }
        if (point[1] > 0) {
            if (heights[point[0]][point[1] - 1] <= heights[point[0]][point[1]] && hasAccess(heights, {point[0], point[1] - 1}, access, visited, width, height)) {
                visited[point[0]][point[1]] = 0;
                access[point[0]][point[1]] = 1;
                return true;
            }
        }
        visited[point[0]][point[1]] = 0;
        return false;
    }

    
};
