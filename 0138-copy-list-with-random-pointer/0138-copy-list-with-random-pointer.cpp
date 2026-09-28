/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertCopyInBetween(Node *head) {
        Node *temp = head;

        while (temp != nullptr) {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = temp->next->next;
        }
    }

    void connectRandomPointers(Node *head) {
        Node *temp = head;

        while (temp != nullptr) {
            Node *copyNode = temp->next;
            copyNode->random = (temp->random != nullptr) ? temp->random->next : nullptr;

            temp = temp->next->next;
        }
    }

    Node *deepCopy(Node *head) {
        Node *temp = head;
        Node *dummyNode = new Node(-1);
        Node *result = dummyNode;

        while (temp != nullptr) {
            result->next = temp->next;
            result = result->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        Node *newHead = dummyNode->next;
        delete dummyNode;

        return newHead;
    }

public:
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);

        return deepCopy(head);
    }
};