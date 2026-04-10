class Solution {
public:
    bool isValidChar(char c) {
        if ('a' <= c && 'z' >= c) return true;
        if ('A' <= c && 'Z' >= c) return true;
        if ('0' <= c && '9' >= c) return true;
        return false;
    }

    char convertToLower(char c) {
        if ('A' <= c && 'Z' >= c) return c - 'A' + 'a';
        return c;
    }

    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;

        while(front < back) {
            while(!isValidChar(s[front]) && front < back) {
                front++;
            }
            while(!isValidChar(s[back]) && front < back) {
                back--;
            }
            if(convertToLower(s[front]) != convertToLower(s[back])) return false;
            front++;
            back--;
        }
        return true;
    }
};
