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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;

        TreeNode* cur = root;
        while (cur != p) {
            pathP.push_back(cur);
            if (cur->val < p->val) cur = cur->right;
            else cur = cur->left;
        }
        pathP.push_back(cur);

        cur = root;
        while (cur != q) {
            pathQ.push_back(cur);
            if (cur->val < q->val) cur = cur->right;
            else cur = cur->left;
        }
        pathQ.push_back(cur);

        int minPath = min(pathP.size(), pathQ.size());
        for (int i = 0; i < minPath; ++i) {
            if (pathP[i] != pathQ[i]) return pathP[i-1];
        }
        return pathP[minPath - 1];
    }
};
