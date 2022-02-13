class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<std::pair<int,int>> numbers;
        for(int i=0;i<nums.size();++i){
            numbers.push_back(std::make_pair(nums[i],i));
        }
        std::sort(numbers.begin(),numbers.end(),[](const std::pair<int,int>& lhs,const std::pair<int,int>& rhs){
            return lhs.first==rhs.first ? lhs.second<rhs.second:lhs.first<rhs.first;
        });
        std::vector<int> result;
        for(int i=0,j=numbers.size()-1;i<j;){
            int sum=numbers[i].first+numbers[j].first;
            if(sum==target){
                 result.push_back(numbers[i].second);
                 result.push_back(numbers[j].second);   
                 break;
            }else if(sum>target){
                j--;
            }else{
                ++i;
            }
        }
        return result;
    }
};