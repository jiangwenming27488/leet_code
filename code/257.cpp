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
    vector<string> vec;
    void getString(TreeNode* root,string str){
        if(root!=NULL){
            if(root->left==NULL && root->right==NULL){
                vec.emplace_back(str+to_string(root->val));
                return;
            }
            getString(root->left,str+to_string(root->val)+"->");
            getString(root->right,str+to_string(root->val)+"->");
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        getString(root,str);
        return vec;
    }
};
