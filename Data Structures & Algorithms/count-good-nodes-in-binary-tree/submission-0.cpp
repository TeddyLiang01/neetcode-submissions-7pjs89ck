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
    void dfs(TreeNode* root, int largest, int &count) {
        if (!root) return;
        if (root->val >= largest) {
            count++;
            largest = root->val;
        }
        dfs(root->left, largest, count);
        dfs(root->right, largest, count);

    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count);
        return count;
    }
};
