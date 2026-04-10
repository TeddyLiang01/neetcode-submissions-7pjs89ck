class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                stack.push(stoi(tokens[i]));
                continue;
            } 
            
            int n2 = stack.top();
            stack.pop();
            int n1 = stack.top();
            stack.pop();
            
            if (tokens[i] == "+") {
                stack.push(n1 + n2);
            } else if (tokens[i] == "-") {
                stack.push(n1 - n2);
            } else if (tokens[i] == "*") {
                stack.push(n1 * n2);
            } else if (tokens[i] == "/"){
                stack.push(n1 / n2);
            }
        }

        return stack.top();
        
    }
};
