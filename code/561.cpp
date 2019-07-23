class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int sum=0;
        for(int index=0;index<len;index+=2){
            sum+=nums[index];
        }
        return sum;
    }
};
