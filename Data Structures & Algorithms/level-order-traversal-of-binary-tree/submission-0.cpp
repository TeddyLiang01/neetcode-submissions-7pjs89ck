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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ret;

        queue<pair<TreeNode*, int>> toVisit;
        toVisit.push(pair<TreeNode*, int> {root, 0});
        while (!toVisit.empty()) {
            pair<TreeNode*, int> toAdd = toVisit.front();
            if (ret.size() <= toAdd.second) {
                ret.push_back(vector<int> {toAdd.first->val});
            } else {
                ret[toAdd.second].push_back(toAdd.first->val);
            }
            toVisit.pop();
            if (toAdd.first->left) {
                toVisit.push(pair<TreeNode*, int> {toAdd.first->left, toAdd.second + 1});
            }
            if (toAdd.first->right) {
                toVisit.push(pair<TreeNode*, int> {toAdd.first->right, toAdd.second + 1});
            }
        }
        return ret;
    }
};

//    1
//  2   3
// 4 5 6 7
