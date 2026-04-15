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
    int findDiameter(TreeNode* node, int& longest) {
        if (!node) return -1;
        int left = 1 + findDiameter(node->left, longest);
        int right = 1 + findDiameter(node->right, longest);
        longest = max(left + right, longest);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int longest = 0;
        findDiameter(root, longest);
        return longest;
    }
};
