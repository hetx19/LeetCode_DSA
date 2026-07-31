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
    vector<TreeNode *> buildTree(int start, int end) {
        vector<TreeNode *> result;

        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftSubTree = buildTree(start, i - 1);
            vector<TreeNode *> rightSubTree = buildTree(i + 1, end);

            for(int j = 0; j < leftSubTree.size(); j++) {
			    for(int k = 0; k < rightSubTree.size(); k++) {
				    TreeNode* root = new TreeNode(i);
				    root->left = leftSubTree[j];
                    root->right = rightSubTree[k];
				    result.push_back(root);
                }
			}            
        }

        return result;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1, n);
    }
};