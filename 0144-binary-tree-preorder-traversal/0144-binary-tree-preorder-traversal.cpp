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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                preOrder.push_back(current->val);
                current = current->right;
            } else {
                TreeNode* previous = current->left;
                while (previous->right != nullptr && previous->right != current) {
                    previous = previous->right;
                }

                if (previous->right == nullptr) {
                    preOrder.push_back(current->val);
                    previous->right = current;
                    current = current->left;
                } else {
                    previous->right = nullptr;
                    current = current->right;
                }
            }
        }
        
        return preOrder;
    }
};
