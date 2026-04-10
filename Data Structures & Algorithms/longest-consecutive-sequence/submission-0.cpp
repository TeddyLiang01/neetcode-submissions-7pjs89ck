class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> allNums{nums.begin(), nums.end()};
        int maximum = 0;

        for (auto& n : allNums) {
            if (allNums.count(n-1) == 0) {
                int cur = n;
                int count = 0;
                while (allNums.count(cur) > 0) {
                    ++count;
                    ++cur;
                }
                maximum = max(count, maximum);
            }
        }
        return maximum;
    }
};
