#include<iostream>
#include<vector>
using namespace std; 
int findDuplicate(vector<int>& nums) {
    int left=1,right=nums.size()-1;
    long mid=0;
    int count=0;
    while(left<=right){
        count=0;
        mid=(left+right)/2;
        for(int& num:nums){
            if(num<=mid) ++count;
        }
        if(count<=mid) left=mid+1;
        else right=mid-1;
    }
    return left;
}
int main(){
	std::vector<int> vec={1,3,4,2,2};
	std::cout<<"duplicated element:"<<findDuplicate(vec)<<std::endl;
	return 0;
}
