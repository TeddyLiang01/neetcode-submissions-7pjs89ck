class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for (auto c : s) {
            if (count.count(c) == 0) count[c] = 1;
            else count[c]++;
        }

        for (auto c : t) {
            if (count.count(c) == 0) return false;
            else count[c]--;
        }

        for (auto pair : count) {
            if (pair.second != 0) return false;
        }
        return true;
    }
};
