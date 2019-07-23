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
    vector<vector<int>> vec;
    void getResult(TreeNode* root,int index){
        if(root!=NULL){
            if(index>vec.size()){
                vector<int> temp={root->val};
                vec.emplace_back(temp);
            }
            else{
                vec[index-1].emplace_back(root->val);
            }
            getResult(root->left,index+1);
            getResult(root->right,index+1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        getResult(root,1);
        return vec;
    }
};
