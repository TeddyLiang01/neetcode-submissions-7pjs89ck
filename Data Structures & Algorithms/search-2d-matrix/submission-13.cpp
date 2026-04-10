class Solution {
public:
    int getIndex(vector<vector<int>>& matrix, int index) {
        int whichRow = index / matrix[0].size();
        int whichCol = index % matrix[0].size();
        return matrix[whichRow][whichCol];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;

        while (l <= r) {
            int mid = (r + l) / 2;
            int midNum = getIndex(matrix, mid);
            cout << midNum << endl;
            if (target == midNum) return true;
            if (target > midNum) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
