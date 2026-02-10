/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *> st;
    bool reverse = true;

private:
    void pushAll(TreeNode* node) {
        for (; node != NULL;) {
            st.push(node);
            if (reverse == true) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        if (reverse == false) {
            pushAll(topNode->right);
        } else {
            pushAll(topNode->left);
        }
        return topNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next(), j = right.next();
        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j > k) {
                j = right.next();
            } else {
                i = left.next();
            }
        }

        return false;
    }
};