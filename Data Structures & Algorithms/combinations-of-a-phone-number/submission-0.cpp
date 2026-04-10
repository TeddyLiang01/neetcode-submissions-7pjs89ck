class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_set<string> res;
        vector<string> resStr;

        if (digits.size() == 0) return resStr;

        unordered_map<int, vector<string>> letters;
        letters['2'] = {"a", "b", "c"};
        letters['3'] = {"d", "e", "f"};
        letters['4'] = {"g", "h", "i"};
        letters['5'] = {"j", "k", "l"};
        letters['6'] = {"m", "n", "o"};
        letters['7'] = {"p", "q", "r", "s"};
        letters['8'] = {"t", "u", "v"};
        letters['9'] = {"w", "x", "y", "z"};

        for (auto s : letters[digits[0]]) {
            res.insert(s);
        }

        for (int i = 1; i < digits.size(); ++i) {
            unordered_set<string> next;
            for (auto r : res) {
                for (auto s : letters[digits[i]]) {
                    next.insert(r + s);
                }
            }
            res = move(next);
        }
        for (auto r : res) resStr.push_back(r);
        return resStr;
    }
};
