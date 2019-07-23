#include<iostream>
#include<algorithm>
using namespace std;

vector<int> numbers;
int canRob(int index,vector<int>& nums){
	if(index<0) return 0;
	if(numbers[index]>0) return numbers[index];
    numbers[index]=max(canRob(index-2,nums)+nums[index],canRob(index-1,nums));
    return numbers[index];
}
int rob(vector<int>& nums) {
    int size=nums.size();
    numbers.resize(size,-1);
    return canRob(size-1,nums);
}
int main(){
	std::vector<int> vec={1,2,3,1};
	std::cout<<"result:"<<rob(vec)<<std::endl;
	return 0;
}
    
