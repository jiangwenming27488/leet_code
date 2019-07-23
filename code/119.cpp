#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0 || rowIndex==1) return vector<int>(rowIndex+1,1);
        vector<int> vec(2,1);
        int idx=2;
        while(idx<=rowIndex){
            for(int i=idx;i>=1;--i){
                vec[i]=vec[i]+vec[i-1];
            }
            vec[0]=1;
            vec.emplace_back(1);
            ++idx;
        }
        return vec;
    }
};
int main(){
	std::cout<<"result:"<<"{";
	Solution s;
	vector<int> res=s.getRow(3);
	for(auto& element:res){
		std::cout<<element<<" ";
	}
	std::cout<<"}"<<std::endl;
	return 0;
}
