#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void getResult(int index,vector<int>& nums,int sum,int S,int size){
        if(index==size){
        	total+=(sum==S);
            return ;
        }
        getResult(index+1,nums,sum+nums[index],S,size);
        getResult(index+1,nums,sum-nums[index],S,size);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
    	total=0;
        getResult(0,nums,0,S,nums.size());
        return total;
    }
private:
    int total;
};
int main(){
	std::vector<int> vec={1,1,1,1,1};
	Solution s;
	std::cout<<"result:"<<s.findTargetSumWays(vec,3)<<std::endl;
	return 0; 
}
