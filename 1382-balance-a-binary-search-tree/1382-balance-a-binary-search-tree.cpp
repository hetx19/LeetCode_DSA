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
class Solution {
private:
    void inorder(TreeNode* node, vector<int> &inOrder) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, inOrder);
        inOrder.push_back(node->val);
        inorder(node->right, inOrder);
    }

    TreeNode* build(vector<int> &inOrder, int low, int high) {
        if (low > high) {
            return nullptr;
        }

        int mid = low + ((high - low) / 2);
        TreeNode* node = new TreeNode(inOrder[mid]);
        node->left = build(inOrder, low, mid - 1);
        node->right = build(inOrder, mid + 1, high);

        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;
        inorder(root, inOrder);

        int n = inOrder.size();

        return build(inOrder, 0, n - 1);
    }
};