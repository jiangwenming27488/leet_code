class Solution {
public:
    vector<int> vec;
    void getNodeNumber(TreeNode* root){
        if(root!=NULL){
            getNodeNumber(root->left);
            vec.emplace_back(root->val);
            getNodeNumber(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        getNodeNumber(root);
        long minValue=5000000000;
        long value=0;
        for(int i=0;i<vec.size()-1;++i){
            value=vec[i+1]-vec[i];
            if(value<minValue) minValue=value;
        }
        return minValue;
    }
};
