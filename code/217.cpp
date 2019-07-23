#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    set<int> _set(nums.begin(),nums.end());
    return _set.size()!=nums.size();
}
int main(){
	std::vector<int> vec={1,1,1,3,3,4,3,2,4,2};
	std::cout<<"result:"<<containsDuplicate(vec)<<std::endl;
	return 0;
}
