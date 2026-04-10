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

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *prev = nullptr;
        ListNode *cur = slow->next;
        slow->next = nullptr;

        while (cur) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        ListNode *backCur = prev;
        ListNode *frontCur = head->next;
        cur = head;
        while (frontCur) {
            cur->next = backCur;
            backCur = backCur->next;
            cur = cur->next;
            cur->next = frontCur;
            frontCur = frontCur->next;
            cur = cur->next;
        }

        if (backCur) {
            cur->next = backCur;
            cur = cur->next;
        }
        cur->next = nullptr;
        


    }
};
