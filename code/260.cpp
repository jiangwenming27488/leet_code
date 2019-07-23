#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();++i){
        	sum^=nums[i];
		}
		int flag=sum&(-sum);
		vector<int> vec(2,0);
		for(auto& element:nums){
			if(element&flag){
				vec[0]^=element;
			}else{
				vec[1]^=element;
			}
		}
		return vec;
    }
};
int main(){
	std::vector<int> vec={1,2,1,3,2,5};
	Solution s;
	std::vector<int> vecs=s.singleNumber(vec);
	std::cout<<"result:"<<vecs[0]<<"   "<<vecs[1]<<std::endl;
	return 0;
}
