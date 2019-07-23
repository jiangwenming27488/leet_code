#include<iostream>
#include<vector>
using namespace std;
int totalHammingDistance(vector<int>& nums) {
	int  count=0,sum=0;
	int size=nums.size();
	for(int index=0;index<32;++index){
		count=0;
	    for(auto& element:nums){
	    	if(element&1==1){
	    		++count;
			}
			element=element>>1;
		}
		sum+=count*(size-count);
	}
	return sum;
}
int main(){
	std::vector<int> vec={4,14,2};
	std::cout<<"result:"<<totalHammingDistance(vec)<<std::endl;
	return 0;
}
