class Node {
public:
    string url;
    Node *next;
    Node *prev;

    Node() : url(""), next(nullptr), prev(nullptr){};
    Node(string url) : url(url), next(nullptr), prev(nullptr) {}
    Node(string url, Node *next, Node *prev) : url(url), next(next), prev(prev) {}
};

class BrowserHistory {
private:
    Node *current;

public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node *newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    string back(int steps) {
        while (steps > 0) {
            if (current->prev != nullptr) {
                current = current->prev;
                steps--;
            } else {
                break;
            }
        }

        return current->url;
    }
    
    string forward(int steps) {
        while (steps > 0) {
            if (current->next != nullptr) {
                current = current->next;
                steps--;
            } else {
                break;
            }
        }

        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */