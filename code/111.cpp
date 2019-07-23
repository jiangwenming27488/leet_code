/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int a=minDepth(root->left)+1;
        int b=minDepth(root->right)+1;
        if(a==1||b==1) return a+b-1;
        return min(a,b);
    }
};
