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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* curr = head; ListNode* temp = head->next;

        while (temp != nullptr) {
            if (temp->val == curr->val) {
                temp = temp->next;
            } else {
                curr->next = temp;
                curr = temp;
                temp = temp->next;
            }
        }
        curr->next = nullptr;
        
        return head;
    }
};