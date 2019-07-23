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
    int getDepth(TreeNode* node){
        if(node==NULL) return 0;
        return max(getDepth(node->left),getDepth(node->right))+1;
    }
    bool get(TreeNode* root){
        if(root==NULL) return true;
        if(abs(getDepth(root->left)-getDepth(root->right))>1){
            return false;
        }
        return get(root->left) && get(root->right);
    }
    bool isBalanced(TreeNode* root) {
        return get(root);
    }
};
