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
    TreeNode* build(const vector<int>& inorder,const vector<int>& postorder,int istart,int iend,int pstart,int pend){
        if(istart<iend || pstart<pend) return NULL;
        int pos=0;
        for(pos=istart;pos>=iend;--pos){
            if(inorder[pos]==postorder[pstart]) break;
        }
        TreeNode* node=new TreeNode(postorder[pstart]);
        node->left=build(inorder,postorder,pos-1,iend,pstart-(istart-pos)-1,pend);
        node->right=build(inorder,postorder,istart,pos+1,pstart-1,pstart-(istart-pos));
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=inorder.size();
        return build(inorder,postorder,len-1,0,len-1,0);
    }
};
