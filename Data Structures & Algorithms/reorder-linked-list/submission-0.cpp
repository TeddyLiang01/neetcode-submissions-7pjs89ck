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
    void reorderList(ListNode* head) {
        if (!head || !head->next ||!head->next->next) {
            return;
        }
        
        vector<ListNode*> nodes;
        ListNode *iter = head;
        while(iter) {
            nodes.push_back(iter);
            iter = iter->next;
        }

        int frontI = 0;
        int backI = nodes.size() - 1;

        while (frontI < backI) {
            nodes[frontI]->next = nodes[backI];
            ++frontI;
            nodes[backI]->next = nodes[frontI];
            --backI;
        }
        nodes[frontI]->next = nullptr;
    }
};

// 0 1
//       
