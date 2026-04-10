class Solution {
public:
    int findDigitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += ((n % 10) * (n % 10));
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            seen.insert(n);
            n = findDigitSum(n);
            if (seen.count(n) > 0) return false;
        }
        return true;
    }
};
