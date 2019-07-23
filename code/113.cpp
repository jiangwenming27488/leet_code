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
    vector<int> path;
    vector<vector<int>> result;
    void getResult(TreeNode* root,int target){
        if(root!=NULL){
            path.emplace_back(root->val);
            if(root->left==NULL && root->right==NULL){
                if(accumulate(path.begin(),path.end(),0)==target){
                    result.emplace_back(path);
                }
                path.pop_back();
                return;
            }
            getResult(root->left,target);
            getResult(root->right,target);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        getResult(root,sum);
        return result;
    }
};
