class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int islCount = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                set<vector<int>> toVisit;
                if (grid[i][j] == '1') {
                    ++islCount;
                    toVisit.insert({i, j});
                    while (toVisit.size() != 0) {
                        auto toCheck = *toVisit.begin();
                        toVisit.erase({toCheck[0], toCheck[1]});
                        if (grid[toCheck[0]][toCheck[1]] == '1') {
                            grid[toCheck[0]][toCheck[1]] = '0';

                            if (toCheck[0] > 0) {
                                toVisit.insert({toCheck[0] - 1, toCheck[1]});
                            }
                            if (toCheck[1] > 0) {
                                toVisit.insert({toCheck[0], toCheck[1] - 1});
                            }
                            if (toCheck[0] < grid.size() - 1) {
                                toVisit.insert({toCheck[0] + 1, toCheck[1]});
                            }
                            if (toCheck[1] < grid[0].size() - 1) {
                                toVisit.insert({toCheck[0], toCheck[1] + 1});
                            }   
                        }
                    }
                }
            }
        }
        return islCount;
    }
};
