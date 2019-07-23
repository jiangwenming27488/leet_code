class Solution {
public:
    vector<int> _vec;
    void midVisit(TreeNode* root){
        if(root==NULL) return;
        midVisit(root->left);
        _vec.emplace_back(root->val);
        midVisit(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        midVisit(root);
        return _vec;
    }
};
