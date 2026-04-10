class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // below and see if it is smaller or greater
            // if smaller then binary search current line
            // if bigger check bottom line
        if (matrix.size() == 0) {
            return false;
        } 

        if (target < matrix[0][0]) {
            return false;
        }
        
        if (matrix.size() == 1) {
            return binarySearch(matrix[0], target);
        }

        for (int i = 0; i < matrix.size(); ++i) { 
            if (i == matrix.size() - 1) {
                return binarySearch(matrix[i], target);
            }
            if (matrix[i][0] <= target && matrix[i + 1][0] > target) {
                return binarySearch(matrix[i], target);
            }
        } 
    }

    bool binarySearch(const vector<int> &line, const int &target) {
        int minIndex = 0;
        int maxIndex = line.size() - 1;

        while (minIndex <= maxIndex) {
            int halfway = (minIndex + maxIndex) / 2;
            if (line[halfway] > target) {
                maxIndex = halfway - 1;
            } else if (line[halfway] < target) {
                minIndex = halfway + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

