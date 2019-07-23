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
    bool getResult(TreeNode* s,TreeNode* t){
        if(s==NULL && t==NULL) return true;
        if(s!=NULL && t!=NULL){
            if(s->val==t->val){
                return getResult(s->left,t->left) && getResult(s->right,t->right);
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool flag=false;
        if(s!=NULL && t!=NULL){
            if(s->val== t->val){
                flag=getResult(s,t);
                if(flag==true) return flag;
            }
            flag=isSubtree(s->left,t) || isSubtree(s->right,t);
        }
        return flag;
    }
};
