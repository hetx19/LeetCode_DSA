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
    bool dfs(TreeNode *node, int sum) {
        if (node == nullptr) {
            return false;
        }

        sum -= node->val;

        if (node->left == nullptr && node->right == nullptr) {
            return sum == 0;
        }

        bool leftPath = dfs(node->left, sum);
        bool rightPath = dfs(node->right, sum);

        return leftPath || rightPath;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};