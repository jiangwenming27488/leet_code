class Solution {
public:
    bool getResult(TreeNode* root,int value){
        if(root==NULL) return true;
        if(root->val!=value) return false;
        return getResult(root->left,value) && getResult(root->right,value);
    }
    bool isUnivalTree(TreeNode* root) {
        return getResult(root,root->val);
    }
};
