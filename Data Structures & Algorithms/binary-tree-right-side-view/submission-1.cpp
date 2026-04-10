/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> toCheck;
        vector<int> ret;
        toCheck.push(root);

        while (!toCheck.empty()) {
            int rightMost;
            int queLen = toCheck.size();
            for (int i = 0; i < queLen; ++i) {
                rightMost = toCheck.front()->val;
                if (toCheck.front()->left) {
                    toCheck.push(toCheck.front()->left);
                }
                if (toCheck.front()->right) {
                    toCheck.push(toCheck.front()->right);
                }
                toCheck.pop();
            }
            ret.push_back(rightMost);
        }

        return ret;
    }
};

//    1
//  2   3
// 4 5 6

