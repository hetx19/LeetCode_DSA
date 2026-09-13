/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *tempA = headA, *tempB = headB;

        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;

            if (tempA == tempB) {
                return tempA;
            }

            if (tempA == nullptr) {
                tempA = headB;
            }

            if (tempB == nullptr) {
                tempB = headA;
            }
        }

        return tempA;
    }
};