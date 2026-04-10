class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int leftBound = -1;
        int rightBound = matrix[0].size();
        int topBound = -1;
        int bottomBound = matrix.size();

        vector<int> ret;

        while (leftBound + 1 < rightBound && topBound + 1 < bottomBound) {
            for (int i = leftBound + 1; i < rightBound; ++i) {
                ret.push_back(matrix[topBound + 1][i]);
            }
            topBound++;
            if (topBound + 1 >= bottomBound) break;

            for (int i = topBound + 1; i < bottomBound; ++i) {
                ret.push_back(matrix[i][rightBound - 1]);
            }
            rightBound--;
            if (leftBound + 1 >= rightBound) break;

            for (int i = rightBound - 1; i > leftBound; --i) {
                ret.push_back(matrix[bottomBound - 1][i]);
            }
            bottomBound--;
            if (topBound + 1 >= bottomBound) break;

            for (int i = bottomBound - 1; i > topBound; --i) {
                ret.push_back(matrix[i][leftBound + 1]);
            }
            leftBound++;
            if (leftBound + 1 >= rightBound) break;
        }
        return ret;
    }
};
