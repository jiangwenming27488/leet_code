#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len=nums.size();
        int result=0;
        for(int i=0;i<32;++i){
        	int count=0;
        	int hid=1<<i;
            for(int j=0;j<len;++j){
            	if(hid&nums[j]){
            		++count; 
				}
            }
            if(count%3) result|=hid;
        }
        return result;
    }
};
int main(){
	std::vector<int> vec={2,2,3,2};
	Solution s;
	std::cout<<"result:"<<s.singleNumber(vec)<<std::endl;
	return 0;
}
