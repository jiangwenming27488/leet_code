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
    void getNumber(TreeNode* node,int k){
        if(index>=k) return;
        if(node!=NULL){
            getNumber(node->left,k);
            ++index;
            if(index==k) aim=node->val;
            getNumber(node->right,k);
        }
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        getNumber(root,k);
        return aim;
    }
private:
    int index;
    int aim;
};
