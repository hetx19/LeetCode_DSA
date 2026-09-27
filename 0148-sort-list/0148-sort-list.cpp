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
    ListNode *findMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *merge(ListNode *leftHead, ListNode *rightHead) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (leftHead != nullptr && rightHead != nullptr) {
            if (leftHead->val < rightHead->val) {
                temp->next = leftHead;
                temp = leftHead;
                leftHead = leftHead->next;
            } else {
                temp->next = rightHead;
                temp = rightHead;
                rightHead = rightHead->next;
            }
        }

        if (leftHead != nullptr) {
            temp->next = leftHead;
        } else {
            temp->next = rightHead;
        }

        ListNode *head = dummy->next;
        delete dummy;

        return head;
    }

    ListNode *mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        middle->next = nullptr;

        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);

        head = merge(leftHead, rightHead);

        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        return mergeSort(head);
    }
};