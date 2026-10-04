class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char data = '\0') : data(data), next(nullptr), prev(nullptr) {}
};

class TextEditor {
private:
    Node* current;

public:
    TextEditor() {
        current = new Node();
    }

    void addText(string text) {
        for (char ch : text) {
            Node* newNode = new Node(ch);

            newNode->prev = current;
            newNode->next = current->next;

            if (current->next != nullptr) {
                current->next->prev = newNode;
            }

            current->next = newNode;
            current = newNode;
        }
    }

    int deleteText(int k) {
        int deleted = 0;

        while (k > 0) {
            if (current->prev != nullptr) {
                Node* temp = current;
                current = current->prev;

                current->next = temp->next;

                if (temp->next != nullptr) {
                    temp->next->prev = current;
                }

                delete temp;
                k--;
                deleted++;
            } else {
                break;
            }
        }

        return deleted;
    }

    string cursorLeft(int k) {
        while (k > 0) {
            if (current->prev != nullptr) {
                current = current->prev;
                k--;
            } else {
                break;
            }
        }

        string ans;
        Node* temp = current;

        for (int i = 0; i < 10 && temp->data != '\0'; i++) {
            ans += temp->data;
            temp = temp->prev;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string cursorRight(int k) {
        while (k > 0) {
            if (current->next != nullptr) {
                k--;
                current = current->next;
            } else {
                break;
            }
        }

        string ans;
        Node* temp = current;

        for (int i = 0; i < 10 && temp->data != '\0'; i++) {
            ans += temp->data;
            temp = temp->prev;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
