class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int digit = digits[i];
            if (digit == 9 && carry == true) {
                digits[i] = 0;
            } else if (carry == true) {
                digits[i] += 1;
                carry = false;
            }
        }
        if (carry == true) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
