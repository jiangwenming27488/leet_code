#include<iostream>
#include<vector>
using namespace std; 
int findPeakElement(vector<int>& nums) {
    int size=nums.size();
    if(size==1) return 0;
    if(nums[0]>nums[1]) return 0;
    else if(nums[size-1]>nums[size-2]) return size-1;
    for(int index=1;index<size-1;++index){
        if(nums[index]>nums[index-1] && nums[index]>nums[index+1]){
            return index;
        }
    }
    return -1;
}
int main(){
	std::vector<int> vec={1,2,3,1};
	std::cout<<"result:"<<findPeakElement(vec)<<std::endl;
	return 0;
 
}
