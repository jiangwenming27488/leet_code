#include<iostream>
#include<vector>
using namespace std;
int uniquePaths(int m, int n) {
    vector<vector<int>> vec(m,vector<int>(n,0));
    for(int i=0;i<m;++i){
     	vec[i][0]=1;
	}
	for(int j=0;j<n;++j){
	 	vec[0][j]=1;
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
			vec[i][j]=vec[i-1][j]+vec[i][j-1];
		}
	}
	return vec[m-1][n-1];
}
int main(){
	std::cout<<"result:"<<uniquePaths(7,3)<<std::endl;
	return 0;
}
