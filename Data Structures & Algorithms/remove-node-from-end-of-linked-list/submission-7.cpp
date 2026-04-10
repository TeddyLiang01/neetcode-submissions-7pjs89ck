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
        if (!head || !head->next) return nullptr;
        
        int count = 0;
        ListNode* cur = head;
        while(cur) {
            ++count;
            cur = cur->next;
        }
        // count is 1 based
        // n is 1 based

        int element = count - n;
        if (element == 0) {
            head = head->next;
            return head;
        }
        
        ListNode* prev = head;
        for (int i = 1; i < element; ++i) {
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return head;
    }
};
