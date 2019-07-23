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
    int getSum(TreeNode* node){
        if(node==NULL) return 0;
        int result=getSum(node->left)+node->val+getSum(node->right);
        multimap<int,int>::iterator pos=m_map.find(result);
        if(pos!=m_map.end()){
            pos->second+=1;
            if(pos->second > count) count=pos->second;
        }else{
            m_map.insert(make_pair(result,1));
        }
        if(count<1) count=1;
        return result;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        getSum(root);
        for(auto& element:m_map){
            if(element.second==count){
                result.emplace_back(element.first);
            }
        }
        return result;
    }
private:
    multimap<int,int> m_map;
    int count;
    vector<int> result;
};
