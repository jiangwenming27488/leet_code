#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>> vec(m,vector<int>(n,0));
    vec[0][0]=!obstacleGrid[0][0];
    for(int i=1;i<m;++i){
        vec[i][0]=(obstacleGrid[i][0]==1 ? 0:vec[i-1][0]);
	}
	for(int i=1;i<n;++i){
        vec[0][i]=(obstacleGrid[0][i]==1 ? 0:vec[0][i-1]);
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
            vec[i][j]=(obstacleGrid[i][j]==1 ? 0:vec[i-1][j]+vec[i][j-1]);
		}
	}
	return vec[m-1][n-1];
}
int main(){
	std::vector<std::vector<int>> vec={{0,0,0},{0,1,0},{0,0,0}};
	std::cout<<"result:"<<uniquePathsWithObstacles(vec)<<std::endl;
	return 0;
}
