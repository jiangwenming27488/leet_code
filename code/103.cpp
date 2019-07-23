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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return vecs;
        
        nodes.emplace_back(root);
        int step=0;
        TreeNode* node=NULL;
        while(!nodes.empty()){
            ++step;
            int count=nodes.size();
            vector<int> vec;
            while(count>0){
                node=*nodes.begin();
                if(step%2==1) vec.emplace_back(node->val);
                else vec.insert(vec.begin(),node->val);
                if(node->left!=NULL) nodes.emplace_back(node->left);
                if(node->right!=NULL) nodes.emplace_back(node->right);
                --count;
                nodes.pop_front();
            }
            vecs.emplace_back(vec);
        }
        return vecs;
    }
private:
    vector<vector<int>> vecs;
    deque<TreeNode*> nodes;
};
