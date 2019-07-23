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
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder,int pstart,int pend,int istart,int iend){
        if(pstart>pend || istart>iend) return NULL;
        int pos=distance(inorder.begin(),find(inorder.begin(),inorder.end(),preorder[pstart]));
        TreeNode* node=new TreeNode(inorder[pos]);
        node->left=buildTree(preorder,inorder,pstart+1,pstart+pos-istart,istart,pos-1);
        node->right=buildTree(preorder,inorder,pstart+pos-istart+1,pend,pos+1,iend);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=preorder.size();
        return buildTree(preorder,inorder,0,len-1,0,len-1);
    }
};
