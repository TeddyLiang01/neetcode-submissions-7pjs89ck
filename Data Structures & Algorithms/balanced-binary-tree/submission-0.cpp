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
    bool isBalanced(TreeNode* root) {
        //base case
        if (!root) {
            return true;
        }

        int heightDiff = getHeight(root->left) - getHeight(root->right);
        if (heightDiff != -1 && heightDiff != 0 && heightDiff != 1) {
            return false;
        }
        if (isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }

    int getHeight(TreeNode* root) {
        //base case
        if (!root) {
            return 0;
        }

        int leftMax = getHeight(root->left);
        int rightMax = getHeight(root->right);
        return 1 + max(leftMax, rightMax);
    }
};
