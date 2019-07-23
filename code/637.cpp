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
    vector<double> nums;
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
    vector<double> averageOfLevels(TreeNode* root) {
        getResult(root,1);
        for(auto& element:vec){
            nums.emplace_back(accumulate(element.begin(),element.end(),0L)*1.0/element.size());
        }
        return nums;
    }
};
