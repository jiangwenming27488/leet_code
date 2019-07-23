#include<iostream>
#include<vector>
int missingNumber(std::vector<int>& nums) {
    long long sum=0;
    long long temp=0;
    int size=nums.size();
    for(int idx=0;idx<size;++idx){
        temp+=nums[idx];
    }
    sum=size*0.5*(size+1);
    return sum-temp;
}
int main(){
    std::vector<int> vec={3,0,1};
    std::cout<<"Number:"<<missingNumber(vec)<<std::endl;
    return 0;
}
