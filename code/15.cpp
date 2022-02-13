class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        std::set<std::vector<int>> sums;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                break;
            }
            if((i-1>=0) && (nums[i]==nums[i-1])){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while( j<k && (nums[k]>=0)){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    sums.insert({nums[i],nums[j],nums[k]});
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return std::vector<std::vector<int>>{sums.begin(),sums.end()};
    }

};