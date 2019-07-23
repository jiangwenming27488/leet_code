class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto pos=find(nums.begin(),nums.end(),target);
        if(pos!=nums.end()){
            return pos-nums.begin();
        }else{
            for(int index=nums.size()-1;index>=0;--index){
                if(nums[index]<target){
                    return index+1;
                }
            }
            if(nums[0]>target){
                return 0;
            }
        }
    }
};
