#include<iostream>
#include<algorithm>
using namespace std;
vector<int> numbers;
int subCanRob(vector<int>& nums,int start,int end){
	numbers.resize(end-start+1,-1);
	numbers[0]=nums[start];
	numbers[1]=max(nums[start],nums[start+1]);
	for(int i=start+2;i<=end;++i){
		numbers[i-start]=max(numbers[i-start-2]+nums[i],numbers[i-start-1]);
	}
	return numbers[end-start];
}
int canRob(vector<int>& nums,int size){
    if(size==0) return 0;
    else if(size==1) return nums[0];
    else if(size==2) return max(nums[0],nums[1]);
    return max(subCanRob(nums,0,size-2),subCanRob(nums,1,size-1));
}
int rob(vector<int>& nums) {
    int size=nums.size();
    return canRob(nums,size);
}
int main(){
	std::vector<int> vec={1,2,3,1};
	std::cout<<"result:"<<rob(vec)<<std::endl;
	return 0;
}
