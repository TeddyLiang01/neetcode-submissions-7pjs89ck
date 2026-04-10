class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charUsed;
        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); ++i) {
            charUsed[s[i]] = 0;
            charUsed[t[i]] = 0;
        }

        for (int i = 0; i < s.length(); ++i) {
            ++charUsed[s[i]];
        }

        for (int i = 0; i < t.length(); ++i) {
            --charUsed[t[i]];
        }

        for (auto i : charUsed) {
            if (i.second != 0) {
                return false;
            }
        }
        return true;
    }
};
