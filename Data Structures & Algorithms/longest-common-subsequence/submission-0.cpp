class Solution {
public:
    int recurse(vector<vector<int>>& mem, string& text1, string& text2, int i1, int i2) {
        if (i1 >= text1.size() || i2 >= text2.size()) return 0;
        
        if (mem[i1][i2] != -1) {
            return mem[i1][i2];
        }

        if (text1[i1] == text2[i2]) {
            mem[i1][i2] = 1 + recurse(mem, text1, text2, i1 + 1, i2 + 1);
        } else {
            mem[i1][i2] = max(recurse(mem, text1, text2, i1 + 1, i2), recurse(mem, text1, text2, i1, i2 + 1));
        }
        return mem[i1][i2];
    }
    int longestCommonSubsequence(string text1, string text2) { 
        vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));
        return recurse(mem, text1, text2, 0, 0);
    }
};
