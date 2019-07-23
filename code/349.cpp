class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        set<int> newset(nums1.begin(),nums1.end());
        for(auto pos=newset.begin();pos!=newset.end();++pos){
            auto result=find(nums2.begin(),nums2.end(),*pos);
            if(result!=nums2.end()) vec.emplace_back(*result);
        }
        return vec;
    }
};
