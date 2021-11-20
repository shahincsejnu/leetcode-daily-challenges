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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;

        int val = root->val;

        if(root->left) root->left->val += (val * 10);
        if(root->right) root->right->val += (val * 10);

        return sumNumbers(root->left) + sumNumbers(root->right);
    }
};