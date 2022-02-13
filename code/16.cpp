class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::vector<int> results(3,0);
        int sum=10000;
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(i>0 && (nums[i]==nums[i-1])){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int tmp=nums[i]+nums[j]+nums[k];
                if(results.empty() || std::abs(target-tmp)<std::abs(target-sum)){
                    results[0]=nums[i];
                    results[1]=nums[j];
                    results[2]=nums[k];
                    sum=tmp;   
                }
                if(k-j>=2){
                    if(std::abs(target-nums[i]-nums[j+1]-nums[k])<std::abs(target-nums[i]-nums[j]-nums[k-1])){
                        j++;
                    }else{
                        k--;
                    }
                }else{
                    k--;
                }
            }
        }
        return sum;
    }
};