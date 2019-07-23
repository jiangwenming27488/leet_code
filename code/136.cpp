#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int size=nums.size();
    int num=0;
    for(int i=0;i<size;++i){
        num=num^nums[i];
    }
    return num;
}
int main(){
	std::vector<int> vec={2,2,1};
	std::cout<<"single number:"<<singleNumber(vec)<<std::endl;
	return 0;
}
