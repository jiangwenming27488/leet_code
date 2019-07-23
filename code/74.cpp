 #include<iostream>
 #include<vector>
 using namespace std;
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size();
    int n=0;
    if(m>0) n=matrix[0].size();
    long L=0;
    long R=n-1;
    long mid=0;
    if(n>0){
        for(int i=0;i<m;++i){
            if(matrix[i][0]<=target && matrix[i][n-1]>=target){
                L=0;
                R=n-1;
                while(L<=R){
                    int mid=(L+R)/2;
                    if(matrix[i][mid]<target){
                        L=mid+1;
                    }else if(matrix[i][mid]==target){
                        return true;
                    }else{
                        R=mid-1;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
	vector<vector<int> > vec={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	cout<<"search target matrix:"<<searchMatrix(vec,3)<<endl;
	return 0;
}
