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
    int getResult(TreeNode* node){
        if(node==NULL) return 0;
        return getResult(node->left)+1+getResult(node->right);
    }
    int countNodes(TreeNode* root) {
        return getResult(root);
    }
};
