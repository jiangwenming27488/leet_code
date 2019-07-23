#include<iostream>
#include<cmath>
using namespace std;
int reverse(int x) {
    bool flag=(x>=0);
    long long number=x;
    number=abs(number);
    long long result=0;
    while(number>0){
        result=number%10+result*10;
        number/=10;
    }
    if(!flag) result=-result;
    if(result>2147483647 || result<-2147483648) return 0;
    return result;
}
int main(){
	std::cout<<"result:"<<reverse(-120)<<std::endl;
	return 0;
}
