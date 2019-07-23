#include<iostream>
#include<vector>
using namespace std; 
bool checkPossibility(vector<int>& nums) {
	int count=0;
    int current=0;
    int index=0;
	while(index<nums.size()-1){
		if(nums[index]>nums[index+1]){
            nums[index]=max(current,nums[index+1]);
            ++count;
            if(count>=2){
			    return false;
		    }
        }else{
            current=nums[index];
            ++index;
        }
        std::cout<<"current:"<<current<<std::endl;
	}  
    return true;
}
int main(){
	std::vector<int> nums={2,3,3,2,4};
	std::cout<<"result:"<<checkPossibility(nums)<<std::endl;
	return 0; 
}
