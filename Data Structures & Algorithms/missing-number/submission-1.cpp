class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int correctTotal = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += nums.at(i);
            correctTotal += i;
        }
        return correctTotal + nums.size() - total;
    }
};
