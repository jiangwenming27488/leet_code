#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum=-1000000000; 
        for(int index=0;index<=nums.size()-k;++index){
            maxsum=max(maxsum,accumulate(nums.begin()+index,nums.begin()+index+k,0L)*1.0/k);
        }
        return maxsum;
    }
};
int main(){
	std::vector<int> vec={1,12,-5,-6,50,3};
	Solution s;
	std::cout<<"result:"<<s.findMaxAverage(vec,4)<<std::endl;
	return 0; 
}
