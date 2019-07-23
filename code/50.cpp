class Solution {
public:
     double getResult(double b,long e){
        if(e==1) return b;
        if(e==0) return 1;
        double result=getResult(b,e>>1);
        result*=result;
        if((e&0x01) ==1){
            result*=b;
        }
        return result;
    }
    double Power(double base, long exponent) {
        bool flag=true;
        if(exponent<0) {
            flag=false;
            exponent=-exponent;
        }
        double result=getResult(base,exponent);
        if(flag) return result;
        return 1.0/result;
    }
    double myPow(double x, int n) {
        return Power(x,n);
    }
};
