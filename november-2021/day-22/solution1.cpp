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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode *left = root->left, *right = root->right;

        if(key < root->val) left = deleteNode(root->left, key);
        else if(key > root->val) right = deleteNode(root->right, key);
        else{
            if(!root->left && !root->right) return NULL;
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            if(!root->left->right){
                root->left->right = root->right;
                return root->left;
            }
            if(!root->right->left){
                root->right->left = root->left;
                return root->right;
            }

            TreeNode *temp = root->left;
            while(1){
                if(!temp->right->right){
                    root->val = temp->right->val;
                    temp->right = temp->right->left;

                    temp = NULL;
                    break;
                }
                temp = temp->right;
            }

            return root;
        }

        root->left = left;
        root->right = right;

        return root;
    }
};