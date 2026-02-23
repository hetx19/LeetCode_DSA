class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* perv = curr->left;

                while (perv->right != nullptr && perv->right != curr) {
                    perv = perv->right;
                }

                if (perv->right == nullptr) {
                    perv->right = curr;
                    curr = curr->left;
                } else {
                    perv->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};