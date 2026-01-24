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
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& mpp) {
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mpp[postorder[postEnd]];
        int numLeft = inRoot - inStart;

        root->left = build(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numLeft - 1, mpp);

        root->right = build(inorder, inRoot + 1, inEnd, postorder, postStart + numLeft, postEnd - 1, mpp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inSize = inorder.size(), postSize = postorder.size();
        if (inSize != postSize) {
            return nullptr;
        }

        unordered_map<int, int> mpp;
        for (int i = 0; i < inSize; i++) {
            mpp[inorder[i]] = i;
        }

        return build(inorder, 0, inSize - 1, postorder, 0, postSize - 1, mpp);
    }
};