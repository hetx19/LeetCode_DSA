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
    int dfs(TreeNode* node, int &maxSum) {
        if(node == nullptr) {
            return 0;
        }

        int left = max(0, dfs(node->left, maxSum));
        int right = max(0, dfs(node->right, maxSum));

        maxSum = max(maxSum, left + right + node->val);

        return max(left, right) + node->val; 
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};