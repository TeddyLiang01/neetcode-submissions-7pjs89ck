class Solution {
public:
    void createParenthesis(int left, int right, string current, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
        }

        if (left != 0) createParenthesis(left - 1, right, current + "(", result);
        if (left < right) createParenthesis(left, right - 1, current + ")", result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        createParenthesis(n, n, "", result);
        return result;
        
        
    }
};

// 1
// ()

// 2
// ()() (())

// 3