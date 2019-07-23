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
    int getResult(TreeNode* root){
        if(root==NULL) return 0;
        int number=0;
        if(root->left!=NULL){
            if(root->left->left==NULL && root->left->right==NULL)
                number+=root->left->val;
        }
        number+=getResult(root->left)+getResult(root->right);
        return number;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return getResult(root);
    }
};
