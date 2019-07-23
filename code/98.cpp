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
    void getResult(TreeNode* node){
        if(node!=NULL){
            getResult(node->left);
            vec.emplace_back(node->val);
            getResult(node->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root!=NULL){
            getResult(root);
            for(int i=0;i<vec.size()-1;++i){
                if(vec[i+1]<=vec[i]) return false;
            }
        }
        return true;
    }
private:
    vector<int> vec;
};
