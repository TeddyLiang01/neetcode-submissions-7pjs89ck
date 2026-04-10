class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftI = 0;
        int rightI = numbers.size() - 1;
        while (true) {
            int curSum = numbers[leftI] + numbers[rightI];
            if (curSum == target) {
                break;
            } else if (curSum < target) {
                ++leftI;
            } else {
                --rightI;
            }
        }
        return {leftI + 1, rightI + 1};
    }
};


// 1 2 3 4
// ^ ^
