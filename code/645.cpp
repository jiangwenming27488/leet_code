#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int findElement(vector<int>& nums){
    map<int,int> _map;
    for(int& element:nums){
        _map[element]++;
        if(_map[element]>=2) return element;
    }
    return 0;
}
vector<int> findErrorNums(vector<int>&& nums) {
    int size=nums.size();
    long long sum=static_cast<long long>((1+size)*size/2);
    long long sum_1=static_cast<long long>(accumulate(nums.begin(),nums.end(),0));
    int element=findElement(nums);
    return vector<int>({element,static_cast<int>(sum-(sum_1-element))});
}
int main(){
	std::vector<int> vec=findErrorNums(std::vector<int>({1,2,2,4}));
	std::cout<<"{";
	for(auto& element:vec){
		std::cout<<element<<" ";
	}
	std::cout<<"}"<<std::endl;
	return 0;
}
