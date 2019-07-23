#include<iostream>
#include<vector>
using namespace std;
int climbStairs(int n) {
	if(n==1 || n==2) return n;
	vector<int> vec(n,0);
	vec[0]=1;
	vec[1]=2;
	for(int index=2;index<n;++index){
		vec[index]=vec[index-1]+vec[index-2];
	}
	return vec[n-1];
}
int main(){
	std::cout<<"result:"<<climbStairs(3)<<std::endl;
	return 0;
}
