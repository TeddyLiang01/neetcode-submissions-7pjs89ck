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
    int maxDepth(TreeNode* root) {
        int max = 0;
        dfs(root, 0, max);
        return max;
    }

    void dfs(TreeNode* root, int level, int &max) {
        if (!root) {
            if (level > max) {
                max = level;
            }
            return;
        }

        dfs(root->left, level + 1, max);
        dfs(root->right, level + 1, max);
    }
};
