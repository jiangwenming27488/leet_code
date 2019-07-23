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
    void getNode(TreeNode* node,int depth){
        if(node==NULL) return;
        if(vec.size()<depth){
            vec.emplace_back(node->val);
        }
        getNode(node->right,depth+1);
        getNode(node->left,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        getNode(root,1);
        return vec;
    }
private:
    vector<int> vec;
};
