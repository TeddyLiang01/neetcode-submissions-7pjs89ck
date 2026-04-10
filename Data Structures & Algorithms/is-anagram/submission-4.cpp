class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        if (s.length() == 0) {
            return true;
        }

        unordered_map<char, int> charCount;
        for (char c : s) {
            if (charCount.count(c) != 0) {
                charCount[c]++;
            } else {
                charCount[c] = 1;
            }
        }

        for (char c : t) {
            if (charCount.count(c) == 0) {
                return false;
            } else {
                charCount[c]--;
                if (charCount[c] == 0) {
                    charCount.erase(c);
                }
            }
        }
        return charCount.empty();


    }
};
