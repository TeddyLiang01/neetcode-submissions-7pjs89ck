class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> inserted;
        for (int n : nums) {
            if (inserted.count(n) > 0) return true;
            inserted.insert(n);
        }
        return false;
    }
};