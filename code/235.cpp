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
    vector<TreeNode*> p1;
    vector<TreeNode*> p2;
    vector<TreeNode*> vec;
    void findElement(TreeNode* root,TreeNode* p,vector<TreeNode*>& tree){
        if(root!=NULL){
            vec.emplace_back(root);
            if(root==p){
                for(auto& element:vec){
                    tree.emplace_back(element);
                }
                vec.pop_back();
                return;
            }else{
                findElement(root->left,p,tree);
                findElement(root->right,p,tree);
                vec.pop_back();
            }
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findElement(root,p,p1);
        findElement(root,q,p2);
        for(int index=p1.size()-1;index>=0;--index){
            if(find(p2.begin(),p2.end(),p1[index])!=p2.end()){
                return p1[index];
            }
        }
        return NULL;
    }
};
