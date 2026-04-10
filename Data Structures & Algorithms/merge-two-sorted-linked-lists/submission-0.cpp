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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode* newHead = nullptr;
        ListNode* curNode = nullptr;
        ListNode* restOf1 = nullptr;
        ListNode* restOf2 = nullptr;

        if (list1->val < list2->val) {
            newHead = list1;
            restOf1 = list1->next;
            restOf2 = list2;
        } else {
            newHead = list2;
            restOf1 = list1;
            restOf2 = list2->next;
        } 
        curNode = newHead; 
         
        while (restOf1 != nullptr || restOf2 != nullptr) {
            if (restOf1 != nullptr && restOf2 != nullptr) {
                if (restOf1->val < restOf2->val) {
                    curNode->next = restOf1;
                    restOf1 = restOf1->next;
                } else {
                    curNode->next = restOf2;
                    restOf2 = restOf2->next;
                }
            } else if (restOf1 == nullptr) {
                curNode->next = restOf2;
                restOf2 = restOf2->next;
            } else {
                curNode->next = restOf1;
                restOf1 = restOf1->next;
            }
            curNode = curNode->next;
        }
        return newHead;
    }
};
