class Solution {
public:
    string findPrefix(string &s1, string &s2) {
        int index = 0;
        string retString = "";
        while (index < s1.size() && index < s2.size()) {
            if (s1[index] != s2[index]) return retString;
            retString += s1[index];
            index++;
        }
        return retString;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string retString = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            retString = findPrefix(retString, strs[i]);
        }
        return retString;
    }
};