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
    bool validBST(TreeNode* root, long long minValue, long long maxValue) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= maxValue || root->val <= minValue) {
            return false;
        }

        return (validBST(root->left, minValue, root->val) && validBST(root->right, root->val, maxValue));
    }

public:
    bool isValidBST(TreeNode* root) {
        return validBST(root, LLONG_MIN, LLONG_MAX);
    }
};