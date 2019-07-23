#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
	int getResult(long long dividend,long long divisor){
		long sign=1;
        long long div=0;
        if((dividend>0 && divisor<0)||(dividend<0 && divisor>0)){  
            sign=-1;
        }
        divisor=abs(divisor);
        dividend=abs(dividend);
        while(dividend>=divisor){
            ++div;
            dividend-=divisor;
        }
        div=sign*div;
        if(div>2147483647 || div<-2147483648) div=2147483647;
        return div;
	}
    int divide(int dividend, int divisor) {
       return getResult(dividend,divisor);
    }
};
int main(){
	Solution s;
	std::cout<<"result:"<<s.divide(-2147483648,-1)<<std::endl;
	return 0;
}
