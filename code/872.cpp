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
    vector<int> vec;
    vector<int> vec1;
    void getResult(TreeNode* node,vector<int>& vec){
        if(node==NULL) return;
        if(node->left==NULL && node->right==NULL){
            vec.emplace_back(node->val);
            return;
        }
        getResult(node->left,vec);
        getResult(node->right,vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getResult(root1,vec);
        getResult(root2,vec1);
        int len1=vec.size();
        int len2=vec1.size();
        if(len1!=len2) return false;
        for(int index=0;index<len1;++index){
            if(vec[index]!=vec1[index]) return false;
        }
        return true;
    }
};
