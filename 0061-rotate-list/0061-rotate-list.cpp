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
    ListNode *findNthNode(ListNode *temp, int k) {
        int counter = 1;

        while (temp != nullptr) {
            if (counter == k) {
                return temp;
            }

            counter++;
            temp = temp->next;
        }

        return temp;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }

        ListNode *tail = head;
        int length = 1;

        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        k = k % length;

        if (k == 0) {
            return head;
        }

        tail->next = head;

        ListNode *newLastNode = findNthNode(head, length - k);
        head = newLastNode->next;
        newLastNode->next = nullptr;

        return head;
    }
};