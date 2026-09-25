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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

        for (auto &head : lists) {
            if (head != nullptr) {
                pq.push({head->val, head});
            } 
        }

        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        while (!pq.empty()) {
            ListNode *node = pq.top().second;
            pq.pop();

            if (node->next != nullptr) {
                pq.push({node->next->val, node->next});
            }

            temp->next = node;
            temp = temp->next;
        }

        ListNode *head = dummyNode->next;
        delete dummyNode;

        return head;
    }
};