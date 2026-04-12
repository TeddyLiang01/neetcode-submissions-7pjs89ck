class Solution {
public:
    bool isSame(unordered_map<char, int>& s1Char, unordered_map<char, int>& window) {
        for (auto& pair : s1Char) {
            if (window.count(pair.first) == 0) return false;
            if (window[pair.first] != pair.second) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Char;
        unordered_map<char, int> window;

        for (int i = 0; i < s1.size(); ++i) {
            s1Char[s1[i]] += 1;
            window[s2[i]] += 1;
        }

        for (int i = 0; i < s2.size() - s1.size() + 1; ++i) {
            if (isSame(s1Char, window)) return true;
            window[s2[i]]--;
            window[s2[i + s1.size()]]++;
        }

        return false;
    }
};
