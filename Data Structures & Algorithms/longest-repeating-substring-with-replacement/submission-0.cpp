class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() == 0) return 0;
        int left = 0;
        int maximum = 0;
        unordered_map<char, int> curWindow;

        int curHigh = 0;

        for (int right = 0; right < s.length(); ++right) {
            if (curWindow.count(s[right]) == 0) curWindow[s[right]] = 1;
            else curWindow[s[right]]++;

            curHigh = max(curHigh, curWindow[s[right]]);

            while (right - left + 1 - curHigh > k) {
                curWindow[s[left]]--;
                left++;
            }
            maximum = max(right - left + 1, maximum);
        }
        return maximum;
    }
};
