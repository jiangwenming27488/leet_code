class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        if(nums.empty()) return vec;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int first,second=0;
        int sum=0;
        for(int i=0;i<len-3;++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<len-2;++j){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                first=j+1;
                second=len-1;
                while(first<second){
                     sum=nums[first]+nums[second]+nums[i]+nums[j];
                     if(sum==target){
                         vector<int> temp={nums[i],nums[j],nums[first],nums[second]};
                         vec.emplace_back(temp);
                         while(first<second && nums[first]==nums[first+1]) ++first;
                         while(first<second && nums[second]==nums[second-1]) --second;
                         ++first;
                         --second;
                     }else if(sum>target){
                         --second;
                     }else ++first;
                }
            }
        }
        return vec;
    }
};
