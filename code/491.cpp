#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
vector<vector<int> > _vec;
vector<int> path;
vector<int> flag;
int _size=0;
void getSub(int index,vector<int>& nums,int size,int pos,int left){
	if(index>=2){
    	if(find(_vec.begin(),_vec.end(),path)==_vec.end())
    		_vec.emplace_back(path);
	}
    if(left==0){
        return ;
    }
    for(int i=pos;i<size;++i){
        if(flag[i]==0){
            if(index==0 || nums[i]>=path[index-1]){
                path.emplace_back(nums[i]);
                flag[i]=1;
                getSub(index+1,nums,size,i+1,left-1);
                flag[i]=0;
                path.pop_back();
            }
        }
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    int size=nums.size();
    flag.resize(size,0);
    getSub(0,nums,size,0,size);
    return _vec;
}
int main(){
	std::vector<int> vec={4,6,7,7};
	_vec=findSubsequences(vec);
	for(auto& ele:_vec){
		std::cout<<"{";
		for(auto& element:ele){
			std::cout<<element<<" ";
		}
		std::cout<<"}"<<std::endl;
	}
	return 0;
}
