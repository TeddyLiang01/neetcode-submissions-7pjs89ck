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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        int rootPoint;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) rootPoint = i;
        }
        preorder.erase(preorder.begin());

        vector<int> left(inorder.begin(), inorder.begin() + rootPoint);
        vector<int> right(inorder.begin() + rootPoint + 1, inorder.end());
        root->left = buildTree(preorder, left);
        root->right = buildTree(preorder, right);
        return root;
    }
};
