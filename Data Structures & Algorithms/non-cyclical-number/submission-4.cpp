class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> seen;

        int squareDigits = n;
        while (squareDigits != 1) {
            int newDigits = 0;
            for (int i = 1; squareDigits / i > 0; i *= 10) {
                int digit = (squareDigits / i) % 10;
                newDigits += digit * digit;
            }
            if (seen.find(newDigits) != seen.end()) {
                break;
            }
            seen[newDigits] = true;
            squareDigits = newDigits;
        }
        if (squareDigits == 1) {
            return true;
        }
        return false;
    }

    // 19
    // seen [82]
    // squareDigits = 82
    // newDigits = 82
    // i = 1; 19 digit = 9
    // i = 10; 1 digit = 1

};
