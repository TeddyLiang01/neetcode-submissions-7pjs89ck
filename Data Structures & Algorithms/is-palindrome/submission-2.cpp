class Solution {
public:
    bool isAlphaNumeric(char c) {
        if ('a' <= c && 'z' >= c) return true;
        if ('A' <= c && 'Z' >= c) return true;
        if ('0' <= c && '9' >= c) return true;
        return false;
    }

    char lowerCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + 'a' - 'A';
        }
        return c;
    }

    bool isPalindrome(string s) {
        int leftI = 0;
        int rightI = s.length() - 1;

        bool hasChar = false;
        for (char c : s) {
            if (isAlphaNumeric(c)) {
                hasChar = true;
                break;
            }
        }
        if (!hasChar) {
            return true;
        }

        while(leftI < rightI) {
            while(!isAlphaNumeric(s[leftI])) {
                ++leftI;
            }

            while(!isAlphaNumeric(s[rightI])) {
                --rightI;
            }

            if (lowerCase(s[leftI]) != lowerCase(s[rightI])) {
                return false;
            }
            ++leftI;
            --rightI;
        }
        return true;
    }
};
