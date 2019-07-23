#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<pair<TreeNode*,int> > trueVec;
    vector<pair<TreeNode*,int> > falseVec;
    vector<pair<TreeNode*,int> >::iterator pos;
    vector<pair<TreeNode*,int> >::iterator findElement(vector<pair<TreeNode*,int> >& vec,TreeNode* node){
        vector<pair<TreeNode*,int> >::iterator pos=find_if(vec.begin(),vec.end(),[&](const pair<TreeNode*,int>& value){
            return value.first==node;
        });
        return pos;
    }
    int getRob(TreeNode* root,bool can){
        int ans=0;
        if(root!=NULL){
            pos=findElement(trueVec,root);
            if(can && pos!=trueVec.end()) ans=pos->second;
            else if(!can && (pos=findElement(falseVec,root))!=falseVec.end()){
                ans=pos->second;
            }else{
                ans=getRob(root->left,true)+getRob(root->right,true);
                falseVec.emplace_back(make_pair(root,ans));
                if(can){
                    ans=max(ans,root->val+getRob(root->left,false)+getRob(root->right,false));
                    trueVec.emplace_back(make_pair(root,ans));
                }
            }
        }
        return ans;
    }
    int rob(TreeNode* root) {
        return getRob(root,true);
    }
};
