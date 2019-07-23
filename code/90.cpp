#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > vec;
vector<int> path;
vector<bool> flag;
vector<int> _tmp;
void calPer(int index,vector<int>& nums,int pos,int k,int size){
    if(index>=k){
        _tmp.clear();
        for(int i=0;i<k;++i){
            _tmp.emplace_back(nums[path[i]]);
        }
        if(find(vec.begin(),vec.end(),_tmp)==vec.end())
            vec.emplace_back(_tmp);
    	return;
    }
    for(int i=pos;i<size;++i){
        if(flag[i]==false){
            path[index]=i;
            flag[i]=true;
            calPer(index+1,nums,i+1,k,size);
            flag[i]=false;
        }
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int size=nums.size();
    path.resize(size);
    flag.resize(size);
    for(int i=0;i<=size;++i){
    	path.clear();
    	flag.clear();
        calPer(0,nums,0,i,size);
    }
    return vec;
}
int main(){
	vector<int> _vec={1,2,2};
	vec=subsetsWithDup(_vec);
	for(int i=0;i<vec.size();++i){
		std::cout<<"{";
		for(auto& element:vec[i]){
			std::cout<<element<<" "; 
		}
		std::cout<<"}"<<std::endl;
	}
	return 0;
}
