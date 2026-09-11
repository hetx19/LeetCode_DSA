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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) { 
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head, *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != nullptr) {
            if (first->val != second->val) {
                reverseList(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverseList(newHead);

        return true;
    }
};