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
    void dfs(TreeNode* node, int &curSize, int &target, int &value) {
        if (!node->left && !node->right) {
            ++curSize;
            if (curSize == target) value = node->val;
            return;
        }
        if (node->left) dfs(node->left, curSize, target, value);

        ++curSize;
        if (curSize == target) value = node->val;
        
        if (node->right) dfs(node->right, curSize, target, value);

        
    }

    int kthSmallest(TreeNode* root, int k) {
        int value;
        int curSize = 0;
        dfs(root, curSize, k, value);
        return value;
    }
};

