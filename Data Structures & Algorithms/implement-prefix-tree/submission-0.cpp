class TreeNode {
public:
    char val;
    bool isEnd;
    vector<TreeNode*> children;
    TreeNode(char c) : val{c}, isEnd{false} {}
};

class PrefixTree {
    TreeNode* root;
public:
    PrefixTree() {
        root = new TreeNode('-');
    }
    
    void insert(string word) {
        TreeNode* cur = root;
        for (char& c : word) {
            bool contains = false;
            for (auto& child : cur->children) {
                if (child->val == c) {
                    contains = true;
                    cur = child;
                    break;
                }
            }
            if (!contains) {
                TreeNode* newNode = new TreeNode(c);
                cur->children.push_back(newNode);
                cur = newNode;
            }
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode* cur = root;
        for (char& c : word) {
            bool contains = false;
            for (auto& child : cur->children) {
                if (child->val == c) {
                    contains = true;
                    cur = child;
                    break;
                }
            }
            if (!contains) return false;
        }
        if (cur->isEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for (char& c : prefix) {
            bool contains = false;
            for (auto& child : cur->children) {
                if (child->val == c) {
                    contains = true;
                    cur = child;
                    break;
                }
            }
            if (!contains) return false;
        }
        return true;
    }
};
