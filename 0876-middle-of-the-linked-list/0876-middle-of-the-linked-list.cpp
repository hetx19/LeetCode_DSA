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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int length = 0;

        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int mid = (length >> 1) + 1;
        temp = head;

        while (temp != nullptr) {
            mid -= 1;

            if (mid == 0) {
                break;
            }
            
            temp = temp->next;
        }

        return temp;
    }
};