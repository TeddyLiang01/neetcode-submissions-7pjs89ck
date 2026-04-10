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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            return nullptr;
        }
        vector<ListNode *> nodeStore;
        ListNode* curNode = head;

        while (curNode) {
            nodeStore.push_back(curNode);
            curNode = curNode->next;
        }

        int pos = nodeStore.size() - n;
        if (pos == 0) {
            return nodeStore[1];
        } else if (pos == nodeStore.size() - 1) {
            nodeStore[nodeStore.size() - 2]->next = nullptr;
            return head;
        } else {
            nodeStore[pos - 1]->next = nodeStore[pos + 1];
        }
        return head;
        


    }
};

// 1 2 3 4 5
// n: 3

// link 2 to 4
// 3 - 1 to 3 + 1
