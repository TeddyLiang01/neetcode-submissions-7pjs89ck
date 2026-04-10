class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l = i, r = i;
            while (s[l] == s[r] && r < s.size() && l >= 0) {
                count++;
                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while(s[l] == s[r] && r < s.size() && l >= 0) {
                count++;
                l--;
                r++;
            }

        }
        return count;
    }
};
