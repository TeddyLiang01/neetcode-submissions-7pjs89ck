class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        vector<int> postfix(nums.size(), 0);

        int temp = 1;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i] = temp;
            temp *= nums[i];
        }

        temp = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            postfix[i] = temp;
            temp *= nums[i];
        }

        vector<int> ret(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            ret[i] = prefix[i] * postfix[i];
        }
        return ret;
    }
};
