#include<vector>
#include<iostream>
#include<algorithm> 
using namespace std;
int minelement=100000;
void cal(int target,int number){
	if(target==0){
		minelement=min(minelement,number);
		return;
	}
	int end=sqrt(target);
	int count=0;
	for(int i=end;i>=1;--i){
		count=target/(i*i);
		cal(target-i*i*count,number+count);
	}
}
int numSquares(int n) {
    cal(n,0); 
	return minelement;  
}
int main(){
	std::cout<<"result:"<<numSquares(12)<<std::endl;
	return 0;
}
