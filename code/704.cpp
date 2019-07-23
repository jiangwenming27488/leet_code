#include<iostream>
#include<vector>
using namespace std; 
int search(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    int mid=0;
    while(left<=right){
        mid=(left+right)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) right=mid-1;
        else left=mid+1;
    }
    return -1;
}
int main(){
	std::vector<int>  vec={-1,0,3,5,9,12};
	std::cout<<"result:"<<search(vec,9)<<std::endl;
	return 0;
}
