/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* df(Node* node, unordered_map<Node*, Node*> &clones) {
        Node* newNode = new Node(node->val);
        clones[node] = newNode;
        for (auto n : node->neighbors) {
            if (clones.count(n) == 1) newNode->neighbors.push_back(clones[n]);
            else newNode->neighbors.push_back(df(n, clones)); 
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<Node*, Node*> clones;
        return df(node, clones);
    }
};
