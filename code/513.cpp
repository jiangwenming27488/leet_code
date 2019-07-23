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
    void getNumber(TreeNode* root,int depth){
        if(root==NULL) return;
        if(m_depth<depth){
            m_value=root->val;
            m_depth=depth;
        }
        getNumber(root->left,depth+1);
        getNumber(root->right,depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        m_depth=-1;
        getNumber(root,0);
        return m_value;
    }
private:
    int m_depth;
    int m_value;
};
