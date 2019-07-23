class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](const int& a,const int b){
            return a>b;
        });
        return nums[k-1];
    }
};
