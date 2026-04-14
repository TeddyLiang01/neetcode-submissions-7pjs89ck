class Solution {
public:
    bool checkString(vector<vector<int>>& memo, string s, int index, int open) {
        if (open < 0 || open > s.size()) return false;
        if (index == s.size()) return open == 0;

        if (memo[index][open] != -1) return memo[index][open];
        if (s[index] == '*') {
            memo[index][open] = checkString(memo, s, index + 1, open + 1) || checkString(memo, s, index + 1, open) 
            || checkString(memo, s, index + 1, open - 1);
            return memo[index][open];
        }
        int originalOpen = open;
        if (s[index] == '(') open++;
        else if (s[index] == ')') open--;

        if (open < 0) return false;
        memo[index][originalOpen] = checkString(memo, s, index + 1, open);
        return memo[index][originalOpen];
    }
    bool checkValidString(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size() + 1, -1));
        return checkString(memo, s, 0, 0);
    }
};
