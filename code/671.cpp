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
    int findSecondMinimumValue(TreeNode* root,int val) {
        if(root==NULL) return -1;
        if(root->val > val) return root->val;
        int left=findSecondMinimumValue(root->left,val);
        int right=findSecondMinimumValue(root->right,val);
        if(left<0 ) return right;
        else if(right<0) return left;
        return min(left,right);
    }
    int findSecondMinimumValue(TreeNode* root){
        return findSecondMinimumValue(root,root->val);
    }
};
