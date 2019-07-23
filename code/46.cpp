#include<iostream>
#include<vector>
using namespace std; 
vector<vector<int>> vec;
vector<int> path(100,0);
vector<int> flag(100,0);
vector<int> _tmp;
void calPermute(int index,vector<int>& nums,int size){
    if(index>=size){
        _tmp.clear();
        for(int i=0;i<size;++i){
        	_tmp.emplace_back(nums[path[i]]);
		}
		vec.emplace_back(_tmp);
    }
    for(int i=0;i<size;++i){
        if(flag[i]==false){
            path[index]=i;
            flag[i]=true;
            calPermute(index+1,nums,size);
            flag[i]=false;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
	vec.clear();
    calPermute(0,nums,nums.size());
    return vec;
}
int main(){
	vector<int> vec1={1,2,3};
	vec=permute(vec1);
	for(int i=0;i<vec.size();++i){
		std::cout<<"{";
		for(int j=0;j<vec[i].size();++j){
			std::cout<<vec[i][j]<<" ";
		}
		std::cout<<"}"<<std::endl;
	}
	return 0;
}
