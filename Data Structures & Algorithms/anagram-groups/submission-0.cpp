class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> sorted;
        for (string str : strs) {
            bool added = false;
            for (vector<string> &subGroup : sorted) {
                if (subGroup.size() != 0 && isAnagram(str, subGroup[0])) {
                    subGroup.push_back(str);
                    added = true;
                }
            }
            if (!added) {
                sorted.push_back(vector<string> {str});
            }
        }
        return sorted;
    }

    bool isAnagram(string str1, string str2) {
        if (str1.length() != str2.length()) {
            return false;
        }

        unordered_map<char, int> chars;
        for (int i = 0; i < str1.length(); ++i) {
            if (chars.find(str1[i]) != chars.end()) {
                ++chars[str1[i]];
            } else {
                chars[str1[i]] = 1;
            }
        }

        for (int i = 0; i < str2.length(); ++i) {
            if (chars.find(str2[i]) == chars.end()) {
                return false;
            } else {
                chars[str2[i]] -= 1;
            }
        }

        for (auto i : chars) {
            if (i.second != 0) {
                return false;
            }
        }
        return true;
    }
};
