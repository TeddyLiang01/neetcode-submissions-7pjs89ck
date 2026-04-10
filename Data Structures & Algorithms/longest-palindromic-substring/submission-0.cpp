class Solution {
public:
    bool isPalindrome(string &s, int p1, int p2) {
        while(p1 < p2) {
            if (s[p1] != s[p2]) {
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }

    string findPalindrome(string &s, int i) {
        int begin = 0;
        while (begin + i - 1 < s.size()) {
            if (isPalindrome(s, begin, begin + i - 1)) return s.substr(begin, i);
            begin++;
        }
        return "";
    }

    string longestPalindrome(string s) {
        string found = "";
        for (int i = s.size(); i > 0; --i) {
            found = findPalindrome(s, i); 
            if (found != "") return found;
        }
        return "";
    }
};
