class Solution {
public:
    vector<int> vec;
    void diffValues(TreeNode* root){
        if(root==NULL) return;
        vec.push_back(root->val);
        diffValues(root->left);
        diffValues(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        diffValues(root);
        sort(vec.begin(),vec.end(),[](const int& a,const int& b){
            return a<b;
        });
        long minValue=5147483647;
        long value=0;
        for(int i=0;i<vec.size()-1;++i){
            value=vec[i+1]-vec[i];
            if(value<minValue) minValue=value;
        }
        return minValue;
    }
};
