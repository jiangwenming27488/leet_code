#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > _vec;
vector<int> path;
vector<int> flag;
void getCal(vector<int>& nums,int size){
	if(path.size()==size){
		if(find(_vec.begin(),_vec.end(),path)==_vec.end()){
			_vec.emplace_back(path);
		}
		return;
	}
	for(int i=0;i<size;++i){
		if(flag[i]==false){
			path.emplace_back(nums[i]);
			flag[i]=true;
			getCal(nums,size);
			flag[i]=false;
			path.pop_back();
		}
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    int size=nums.size();
    flag.resize(size,0);
    getCal(nums,size);
    return _vec;
}
int main(){
	std::vector<int> vec={1,1,2};
	_vec=permuteUnique(vec);
	for(auto& element:_vec){
		std::cout<<"{";
		for(auto& ele:element){
			std::cout<<ele<<" ";
		}
		std::cout<<"}"<<std::endl; 
	}
	return 0;
}
