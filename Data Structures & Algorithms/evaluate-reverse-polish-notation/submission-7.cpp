class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) return stoi(tokens[0]);

        stack<int> st;

        for (int i = 0; i < tokens.size(); ++i) {
            string t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
            
                if (tokens[i] == "+") st.push(num1 + num2);
                else if (tokens[i] == "-") st.push(num1 - num2);
                else if (tokens[i] == "*") st.push(num1 * num2);
                else if (tokens[i] == "/") st.push(num1 / num2);
            } else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
