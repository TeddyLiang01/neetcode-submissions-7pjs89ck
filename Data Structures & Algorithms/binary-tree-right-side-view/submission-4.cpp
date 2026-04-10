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
        vector<int> ret;
        if (!root) return ret; 
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int curSize = q.size();
            for (int i = 0; i < curSize; ++i) {
                if (i == curSize - 1) ret.push_back(q.front()->val);
                TreeNode* tn = q.front();
                q.pop();
                if (tn->left) q.push(tn->left);
                if (tn->right) q.push(tn->right);
            }
        }
        return ret;
    }
};
