class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int islCount = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                set<pair<int, int>> toVisit;
                if (grid[i][j] == '1') {
                    ++islCount;
                    toVisit.insert(pair<int, int> {i, j});
                    while (toVisit.size() != 0) {
                        auto toCheck = *toVisit.begin();
                        toVisit.erase({toCheck.first, toCheck.second});
                        if (grid[toCheck.first][toCheck.second] == '1') {
                            grid[toCheck.first][toCheck.second] = '0';

                            if (toCheck.first > 0) {
                                toVisit.insert({toCheck.first - 1, toCheck.second});
                            }
                            if (toCheck.second > 0) {
                                toVisit.insert({toCheck.first, toCheck.second - 1});
                            }
                            if (toCheck.first < grid.size() - 1) {
                                toVisit.insert({toCheck.first + 1, toCheck.second});
                            }
                            if (toCheck.second < grid[0].size() - 1) {
                                toVisit.insert({toCheck.first, toCheck.second + 1});
                            }   
                        }
                    }
                }
            }
        }
        return islCount;
    }
};
