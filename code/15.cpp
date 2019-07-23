class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > vec;
        int size=nums.size();
        vector<int> temp(3,0);
        sort(nums.begin(),nums.end());
        int left,last,sum=0;
        for(int i=0;i<size-2;++i){
            left=i+1;
            last=size-1;
            while(left<last){
                sum=nums[left]+nums[last]+nums[i];
                if(sum==0){
                    temp[0]=nums[left];
                    temp[1]=nums[last];
                    temp[2]=nums[i];
                    vec.insert(temp);
                }
                if(sum>0){
                    --last;
                }else{
                    ++left;
                }
            }
        }
        return vector<vector<int>>(vec.begin(),vec.end());
    }
};
