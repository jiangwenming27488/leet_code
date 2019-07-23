 #include<iostream>
 #include<vector>
 using namespace std;
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size();
    if(m==0) return false;
	int n=matrix[0].size();
    int j=0;
    m=m-1;
    while(m>=0 && j<n){
    	if(matrix[m][j]==target){
			return true;
		}
    	else if(matrix[m][j]>target){
    		--m;
    	}
    	else ++j;
	}
    return false;
}
int main(){
	vector<vector<int> > vec={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	std::cout<<"searchMatrix:"<<searchMatrix(vec,5)<<std::endl;
	return 0; 
}
