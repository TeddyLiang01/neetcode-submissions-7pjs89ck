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
        if (!root) {
            return {};
        }

        unordered_map<int, int> levelStore; // level, value

        queue<pair<TreeNode*, int>> toCheck;
        toCheck.push(pair<TreeNode*, int> {root, 0});
        while (!toCheck.empty()) {
            pair<TreeNode*, int> toAdd = toCheck.front();
            toCheck.pop();

            if (levelStore.find(toAdd.second) == levelStore.end()) {
                levelStore[toAdd.second] = toAdd.first->val;
            }

            if (toAdd.first->right) {
                toCheck.push(pair<TreeNode*, int> {toAdd.first->right, toAdd.second + 1});
            }
            if (toAdd.first->left) {
                toCheck.push(pair<TreeNode*, int> {toAdd.first->left, toAdd.second + 1});
            }
        }

        vector<int> ret;
        for (int i = 0; i < levelStore.size(); ++i) {
            ret.push_back(levelStore[i]);
        }
        return ret;
    }
};

//    1
//  2   3
// 4 5 6

