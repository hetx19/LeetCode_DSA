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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
		
        ListNode* dummy = new ListNode();
        
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr && current->next) {
            prev->next = current->next;
            current->next = prev->next->next;
            prev->next->next = current;
            
            prev = current;
            current = current->next;
        }

        head = dummy->next;
        delete dummy;
        
        return head;
    }
};