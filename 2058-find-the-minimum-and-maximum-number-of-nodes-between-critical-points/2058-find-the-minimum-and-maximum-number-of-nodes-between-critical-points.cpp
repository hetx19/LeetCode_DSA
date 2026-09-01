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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head;
        ListNode *current = head->next;

        int index = 1;

        int firstCritical = -1, secondCritical = -1, minDistance = INT_MAX;

        while (current->next != nullptr) {
            ListNode *next = current->next;

            bool isMax = current->val > prev->val && current->val > next->val;
            bool isMin = current->val < prev->val && current->val < next->val;

            if (isMax || isMin) {
                if (secondCritical == -1) {
                    firstCritical = index;
                } else {
                    minDistance = min(minDistance, index - secondCritical);
                }

                secondCritical = index;
            }

            prev = current;
            current = next;
            index++;
        }

        if (firstCritical == -1 || firstCritical == secondCritical){
            return {-1, -1};
        }

        int maxDistance = secondCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};