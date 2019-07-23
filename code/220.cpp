class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size=nums.size();
        long num=0;
        long com=t;
        for(int index=0;index<size;++index){
            for(int j=index+1;j<=index+k && j<size;++j){
                num=abs((long)nums[j]-(long)nums[index]);
                if(num<=com)return true;
            }
        }
        return false;
    }
};
