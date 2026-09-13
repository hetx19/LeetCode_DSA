/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* collisionPoint(ListNode *tempA, ListNode *tempB, int difference) {
        while (difference > 0) {
            difference--;
            tempA = tempA->next;
        }

        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA, *temp2 = headB;
        int n1 = 0, n2 = 0;

        while (temp1 != nullptr) {
            n1++;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            n2++;
            temp2 = temp2->next;
        }

        if (n1 > n2) {
            return collisionPoint(headA, headB, n1 - n2);
        }

        return collisionPoint(headB, headA, n2 - n1);
    }
};