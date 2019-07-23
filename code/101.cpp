struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool judge(TreeNode* left,TreeNode* right){
        bool flag=false;
        if(left==NULL && right==NULL) flag=true;
        else if(left!=NULL && right!=NULL){
            if(left->val==right->val){
                flag= judge(left->left,right->right) && judge(left->right,right->left);
            }
        }
        return flag;
    }
    bool isSymmetric(TreeNode* root) {
        return judge(root,root);
    }
};
