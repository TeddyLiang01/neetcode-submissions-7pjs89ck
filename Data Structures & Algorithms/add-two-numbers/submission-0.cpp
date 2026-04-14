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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        bool carry = false;
        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1 && l2) sum = l1->val + l2->val;
            else if (l1) sum = l1->val;
            else if (l2) sum = l2->val;

            if (carry) sum += 1;
            carry = sum >= 10 ? true : false;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head->next;
    }
};
