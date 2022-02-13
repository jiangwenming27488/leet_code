class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        std::set<std::vector<int>> sums;
        for(int i=0;i<nums.size();++i){
            
            if(i>=1 && (nums[i]==nums[i-1])){
                continue;
            }
            for(int j=i+1;j<nums.size();++j){
                if(j>i+1 && (nums[j]==nums[j-1])){
                    continue;
                }
                int start=j+1;
                int end=nums.size()-1;
                while(start<end){
                    long long sum=(long long)(nums[i])+nums[j]+nums[start]+nums[end];
                    if(sum==target){
                        sums.insert({nums[i],nums[j],nums[start],nums[end]});
                        end--;
                    }else if(sum>target){
                        end--;
                    }else{
                        start++;
                    }
                }
            }
        }
        return std::vector<std::vector<int>>{sums.begin(),sums.end()};
    }
};