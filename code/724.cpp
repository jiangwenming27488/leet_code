class Solution {
public:
    int pivotIndex(vector<int>& nums){
        int sum1,sum2=0;
        for(int mid=0;mid<nums.size();++mid){
        	sum1=accumulate(nums.begin(),nums.begin()+mid,0);
        	sum2=accumulate(nums.begin()+mid+1,nums.end(),0);
			if(sum1==sum2) return mid;
		}
		return -1;
    }
};
