#include<iostream>
#include<vector>
using namespace std; 
bool isPerfectSquare(int num) {
    int l=0;
    int r=47000;
    unsigned long mid=0;
    while(l<=r){
        mid=(l+r)/2;
        if(mid*mid==num){
            return true;
        }else if(mid*mid<num){
            l=mid+1;
        }else r=mid-1;
    }
    return false;
}
int main(){
	std::cout<<"isPerfectSquare(16):"<<isPerfectSquare(16)<<std::endl;
	return 0;
}
