class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> inWindow;

        int longest = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (inWindow.count(s[right]) > 0) {
                while (s[left] != s[right]) {
                    inWindow.erase(s[left]);
                    left++;
                }
                left++;
            }
            inWindow.insert(s[right]);
            longest = max(right - left + 1, longest);
        }
        return longest;
    }
};
