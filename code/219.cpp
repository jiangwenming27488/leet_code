#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int size=nums.size();
	for(int i=0;i<size-1;++i){
		for(int j=i+1;j<size;++j){
			if(nums[i]==nums[j] && abs(i-j)<=k) return true;
		}
	}  
	return false;
}
int main(){
	std::vector<int> vec={1,2,3,1,2,3};
	int k=2;
	std::cout<<"result:"<<containsNearbyDuplicate(vec,k)<<std::endl;
}
