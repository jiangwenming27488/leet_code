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
    int getResult(TreeNode* root,int sum){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return sum*10+root->val;
        int a=getResult(root->left,sum*10+root->val);
        int b=getResult(root->right,sum*10+root->val);
        return a+b;
    }
    int sumNumbers(TreeNode* root) {
        return getResult(root,0);
    }
};
