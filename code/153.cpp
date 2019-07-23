class Solution {
public:
    int findMin(vector<int>& nums) {
        int right=nums.size()-1;
        int mid=0;
        int left=0;
        int result=1000000;
        while(left<=right){
            mid=(left+right)/2;
            result=min(result,nums[mid]);
            if(nums[mid]>=nums[right]) left=mid+1;
            else right=mid-1;
        }
        return result;
    }
};
