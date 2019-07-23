#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > vec;
vector<int> path;
vector<bool> flag;
vector<int> _tmp;
void calSubSet(int index,vector<int>& nums,int k,int pos,int size){
    if(index>=k){
        _tmp.clear();
        for(int i=0;i<k;++i){
            _tmp.emplace_back(nums[path[i]]);    
        }
        vec.emplace_back(_tmp);
        return;
    }
    for(int i=pos;i<size;++i){
        if(flag[i]==false){
            path[index]=i;
            flag[i]=true;
            calSubSet(index+1,nums,k,i+1,size);
            flag[i]=false;
        }
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    int size=nums.size();
    path.resize(size);
    flag.resize(size);
    for(int k=0;k<=size;++k){
        calSubSet(0,nums,k,0,size);
    }
    return vec;
}
int main(){
	std::vector<int> _vec={1,2,3};
	vec=subsets(_vec);
	for(int i=0;i<vec.size();++i){
		std::cout<<"{";
		for(auto& element:vec[i]){
			std::cout<<element<<" ";
		}
		std::cout<<"}"<<std::endl;
	}
	return 0;
}
