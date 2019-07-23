#include<iostream>
#include<vector>
using namespace std;
vector<int> path;
vector<int> flag;
vector<vector<int> > vec;
vector<int> _tmp; 
void calcombinationSum3(int index,int n,int sum,int pos,int k){
	if(index==k){
		_tmp.clear();
		if(sum==n){
			for(int i=0;i<index;++i){
				_tmp.emplace_back(path[i]);	
			}
			vec.emplace_back(_tmp);
		}
		return;
	}
	for(int i=pos;i<=9;++i){
		if(flag[i]==false){
			path[index]=i;
			flag[i-1]=true;
			calcombinationSum3(index+1,n,sum+i,i+1,k);
			flag[i-1]=false;
		}
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	path.resize(9);
	flag.resize(9);
	calcombinationSum3(0,n,0,1,k);
	return vec;
}
int main(){
	vec=combinationSum3(3,9);
	for(int i=0;i<vec.size();++i){
		std::cout<<"{";
		for(auto& element:vec[i]){
			std::cout<<element<<" ";
		}
		std::cout<<"}"<<std::endl;
	} 
	return 0;
}
