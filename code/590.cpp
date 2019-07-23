class Solution {
public:
    vector<int> _vec;
    void backVisit(Node* root){
        if(root!=NULL){
            for(auto& element:root->children){
                backVisit(element);
            }
            _vec.emplace_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        backVisit(root);
        return _vec;
    }
};
