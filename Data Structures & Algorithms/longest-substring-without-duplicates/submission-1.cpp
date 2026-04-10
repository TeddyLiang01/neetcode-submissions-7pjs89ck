class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }

        int leftI = 0;
        int rightI = 0;
        int longest = 1;

        unordered_map<char, int> visited;
        while (rightI < s.length()) {
            if (visited.find(s[rightI]) == visited.end()) {
                visited[s[rightI]] = rightI;
                if (rightI - leftI + 1 > longest) {
                    longest = rightI - leftI + 1;
                }
                ++rightI;
            } else {
                int eraseIndex = visited[s[rightI]];
                while (leftI <= eraseIndex) {
                    visited.erase(s[leftI]);
                    ++leftI;
                }
            }
        }
        return longest;
    }
};


