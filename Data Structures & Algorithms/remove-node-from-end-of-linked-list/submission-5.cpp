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

        ListNode* leftP = head;
        ListNode* rightP = head;
        int counter = n;
        while (counter > 0) {
            rightP = rightP->next;
            --counter;
        }

        if (!rightP) {
            return head->next;
        }

        while (rightP->next) {
            rightP = rightP->next;
            leftP = leftP->next;
        }   

        leftP->next = leftP->next->next;
        return head;
    }
};

// 1 2 3
// ^ ^
// counter: 0 want to remove 4
