/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        vector<ListNode*> visited;
        ListNode *curNode = head;
        while (curNode->next != nullptr) {
            if (inVector(visited, curNode->next)) {
                return true;
            }
            visited.push_back(curNode->next);
            curNode = curNode->next;
        }
        return false;
    }
    bool inVector(vector<ListNode*>& vec, ListNode* node) {
        for (auto i : vec) {
            if (i == node) {
                return true;
            }
        }
        return false;
    }
};
