#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std; 
int lengthOfLIS(vector<int>& nums) {
     int size=nums.size();
	 vector<int> len(size,0);
	 int path=0;
	 int L,R=0;
	 int mid=0;
	 vector<int> min_element(size,100000000);
	 for(int index=0;index<size;++index){
		len[index]=1;
		L=1,R=path;
		while(L<=R){
			mid=(L+R)/2;
			if(nums[index]>min_element[mid]){
				len[index]=mid+1;
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		min_element[len[index]]=min(min_element[len[index]],nums[index]);
		path=max(len[index],path);
	 } 
	 return path;       
}
int main(){
	std::vector<int> vec={10,9,2,5,3,7,101,18};
	std::cout<<"max path:"<<lengthOfLIS(vec)<<std::endl;
	return 0;
}
