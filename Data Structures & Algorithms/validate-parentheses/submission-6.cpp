class Solution {
public:
    bool isValid(string s) {
        vector<char> charStack;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') charStack.push_back('(');
            else if (s[i] == '[') charStack.push_back('[');
            else if (s[i] == '{') charStack.push_back('{');       
            else if (s[i] == ')') {
                if (charStack.empty() || charStack.back() != '(') return false;
                charStack.pop_back();
            }
            else if (s[i] == ']') {
                if (charStack.empty() || charStack.back() != '[') return false;
                charStack.pop_back();
            }
            else if (s[i] == '}') {
                if (charStack.empty() || charStack.back() != '{') return false;
                charStack.pop_back();
            }
        }

        return charStack.empty();
    }
};
