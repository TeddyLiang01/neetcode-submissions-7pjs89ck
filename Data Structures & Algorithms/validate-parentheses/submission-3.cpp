class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for (char c : s) {
            if (c == ')') {
                if (charStack.empty() || charStack.top() != '(') return false;
                charStack.pop();
            } else if (c == '}') {
                if (charStack.empty() || charStack.top() != '{') return false;
                charStack.pop();
            } else if (c == ']') {
                if (charStack.empty() || charStack.top() != '[') return false;
                charStack.pop();
            } else {
                charStack.push(c);
            }
        }
        return charStack.empty();
    }
};
