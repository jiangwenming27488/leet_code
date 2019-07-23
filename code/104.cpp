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
    int getMax(TreeNode* root){
        if(root==NULL) return 0;
        return max(getMax(root->right),getMax(root->left))+1;
    }
    int maxDepth(TreeNode* root) {
        return getMax(root);
    }
};
