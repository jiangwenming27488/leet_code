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
    void getResult(list<TreeNode*>& m_list,int count){
        if(count==0) return;
        int maxele=(*m_list.begin())->val;
        for(TreeNode* &element:m_list){
            if((element->val)>maxele) maxele=element->val;
        }
        vec.emplace_back(maxele);
        if(count==0) return;
        while(count>0){
            if((*m_list.begin())->left!=NULL){
                m_list.emplace_back((*m_list.begin())->left);
            }
            if((*m_list.begin())->right!=NULL){
                m_list.emplace_back((*m_list.begin())->right);
            }
            --count;
            m_list.pop_front();
        }
        getResult(m_list,m_list.size());
    }
    vector<int> largestValues(TreeNode* root) {
        list<TreeNode*> m_list;
        if(root!=NULL) 
            m_list.emplace_back(root);
        getResult(m_list,m_list.size());
        return vec;
    }
private:
    vector<int> vec;
    list<TreeNode*>::iterator pos;
};
