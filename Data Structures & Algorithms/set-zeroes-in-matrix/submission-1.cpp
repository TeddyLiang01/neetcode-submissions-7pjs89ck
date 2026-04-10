class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstCol = 1;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    if (col == 0) firstCol = 0;
                    else matrix[0][col] = 0;
                }
            }
        }

        for (int row = 1; row < matrix.size(); ++row) {
            for (int col = 1; col < matrix[0].size(); ++col) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) matrix[row][col] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                matrix[0][col] = 0;
            }
        }
        
        if (firstCol == 0) {
            for (int row = 0; row < matrix.size(); ++row) {
                matrix[row][0] = 0;
            }
        } 
    }
};
