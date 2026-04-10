class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            while (!isAlphaNumeric(s[start])) {
                ++start;
            }
            while (!isAlphaNumeric(s[end])) {
                --end;
            }
            if (toLower(s[start]) != toLower(s[end])) {
                if (start > end) {
                    break;
                }
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
    
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A'); 
        }
        return c;
    }

    bool isAlphaNumeric(char c) {
        if (c >= 'a' && c <= 'z') {
            return true;
        } else if (c >= 'A' && c <= 'Z') {
            return true;
        } else if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
};
