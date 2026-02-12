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
class NodeVal {
public:
    int minNode, maxNode, sum;
    bool isBST;

    NodeVal(int minNode, int maxNode, int sum, bool isBST) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->isBST = isBST;
    }
};

class Solution {
private:
    int maxSum = 0;

    NodeVal helper(TreeNode* root) {
        if (!root) {
            return NodeVal(INT_MAX, INT_MIN, 0, true);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.isBST && right.isBST &&
            left.maxNode < root->val &&
            root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);

            return NodeVal(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum,
                true
            );
        }

        return NodeVal(0, 0, 0, false);
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};