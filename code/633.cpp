#include<iostream>
#include<cmath>
using namespace std;
bool judgeSquareSum(int c) {
    int l=0;
    int r=sqrt(c);
    int mid=0;
    while(l<=r){
        mid=l*l+r*r;
        if(mid==c) return true;
        else if(mid<c) ++l;
        else --r;
    }
    return false;
}
int main(){
	std::cout<<"result:"<<judgeSquareSum(16)<<std::endl;
	return 0;
}
