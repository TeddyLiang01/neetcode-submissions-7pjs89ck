class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool final = false;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] + 1 == 10) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }

            if (i == 0) final = true;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
