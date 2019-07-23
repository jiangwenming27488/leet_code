class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close=10000000;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for(int i=0;i<len;++i){
            int left=i+1,right=len-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                close=abs(target-close)>abs(target-sum)? sum:close;
                if(sum==target) break;
                else if(sum>target){
                    --right;
                }else ++left;
            }
        }
        return close;
    }
};
