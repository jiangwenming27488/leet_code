/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        vec.emplace_back(root);
        while(!vec.empty()){
            int count=vec.size();
            TreeLinkNode* node=NULL;
            while(count-->0){
                TreeLinkNode* temp=vec[0];
                if(temp->left) vec.emplace_back(temp->left);
                if(temp->right) vec.emplace_back(temp->right);
                if(node==NULL) node=temp;
                else{
                    node->next=temp;
                    node=node->next;
                }
            
                vec.pop_front();
            }
            if(node!=NULL) node->next=NULL;
        }
    }
private:
    deque<TreeLinkNode*> vec;
};
