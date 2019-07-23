#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > _vec;
bool checkEdge(int x,int y,int rows,int cols){
	return x>=0 && x<rows && y>=0 && y<cols;
}
bool check(int x,int y,int xx,int yy,vector<vector<int> >& matrix,int rows,int cols){
	return checkEdge(x,y,rows,cols)&& checkEdge(xx,yy,rows,cols) && matrix[xx][yy]>matrix[x][y];
}
int getLongest(int row,int col,vector<vector<int> >& matrix,int rows,int cols){
	if(_vec[row][col]>0) return _vec[row][col];
	int _max=1;
    for(int idx=-1;idx<=1;++idx){
    	for(int idy=-1;idy<=1;++idy){
     		if(abs(idx+idy)==1){
     			if(check(row,col,row+idx,col+idy,matrix,rows,cols)){
     				_max=max(_max,1+getLongest(row+idx,col+idy,matrix,rows,cols));
				}
			}
		}
	} 
	_vec[row][col]=_max;
	return _vec[row][col];  
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int rows=matrix.size();
    if(rows==0) return 0;
    int cols=matrix[0].size();
    int increase=0;
    _vec.resize(rows,vector<int>(cols,0));
    for(int idx=0;idx<rows;++idx){
        for(int j=0;j<cols;++j){
            increase=max(increase,getLongest(idx,j,matrix,rows,cols));
        }
    }
    return increase;
}
int main(){
	std::vector<std::vector<int> > vec={{9,9,4},{6,6,8},{2,1,1}};
	std::cout<<"longestIncreasingPath(vec):"<<longestIncreasingPath(vec)<<std::endl;
	return 0;
}
