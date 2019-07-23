class Solution {
public:
    vector<int> _vec;
    void preVisit(Node* root){
        if(root!=NULL){
            _vec.emplace_back(root->val);
            for(Node* &element:root->children){
                preVisit(element);
            }
        }
    }
    vector<int> preorder(Node* root) {
        preVisit(root);
        return _vec;
    }
};
