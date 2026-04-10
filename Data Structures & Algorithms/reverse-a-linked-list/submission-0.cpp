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
    ListNode* reverseList(ListNode* head) {
        // loop through the list
        // keep track of the previous node and next node
        // link current node onto previous node
        // move on the next node

        if (head == nullptr) {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *current = head;
        
        while (current->next != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        if (current->next == nullptr && prev != nullptr) {
            current->next = prev;
        }
        return current;
        
    }
};
