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
    TreeNode* buildTree(const vector<int>& nums,int start,int end){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=buildTree(nums,start,mid-1);
        node->right=buildTree(nums,mid+1,end);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        return buildTree(nums,0,len-1);
    }
};
