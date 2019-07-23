class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxcnt=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1) count++;
            else {
                if(maxcnt<count)maxcnt=count;
                count=0;
            }
        }
        if(count>maxcnt) maxcnt=count;
        return maxcnt;
    }
};
