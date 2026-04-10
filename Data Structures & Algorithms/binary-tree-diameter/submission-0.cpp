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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }

    int dfs(TreeNode* root, int& diameter) {
        if (!root) {
            return -1;
        }

        int maxLeft = dfs(root->left, diameter) + 1;
        int maxRight = dfs(root->right, diameter) + 1;
        if (diameter < maxRight + maxLeft) {
            diameter = maxRight + maxLeft;
        }
        return maxLeft >= maxRight ? maxLeft : maxRight;
    }

    
};
