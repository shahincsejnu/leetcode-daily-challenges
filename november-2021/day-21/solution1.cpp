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
    TreeNode *helper(vector<int> &in, vector<int> &post, int lo1, int hi1, int lo2, int hi2)
    {
        if(lo1 > hi1 || lo2 > hi2) return NULL;

        TreeNode *temp = new TreeNode(post[hi2]);

        if(lo2 == hi2) return temp;

        int pos = -1;
        for(int i = lo1; i <= hi1; i++){
            if(in[i] == post[hi2]){
                pos = i;
                break;
            }
        }

        int pichone = pos-lo1, samne = hi1-pos;

        temp->left = helper(in, post, lo1, pos-1, lo2, hi2-1-samne);
        temp->right = helper(in, post, pos+1, hi1, lo2+pichone, hi2-1);

        return temp;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        return helper(inorder, postorder, 0, n-1, 0, n-1);
    }
};