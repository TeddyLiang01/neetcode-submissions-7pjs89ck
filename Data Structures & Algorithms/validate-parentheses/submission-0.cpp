class Solution {
public:
    bool isValid(string s) {
        // read string left to right

        // put char into array if it is open bracket
        // check and remove open bracket if it is close bracket
        vector<char> brackets;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                brackets.push_back(s[i]);
            } else {
                if (brackets.empty()) {
                    return false;
                }

                char lastChar = brackets.back();
                if (s[i] == ')') {
                    if (lastChar != '(') {
                        return false;
                    }
                    brackets.pop_back();
                } else if (s[i] == '}') {
                    if (lastChar != '{') {
                        return false;
                    }
                    brackets.pop_back();
                } else if (s[i] == ']') {
                    if (lastChar != '[') {
                        return false;
                    }
                    brackets.pop_back();
                }
            }
        }

        if (brackets.empty()) {
            return true;
        }
        return false;
    }
};
