#include<iostream>
using namespace std;
string convertToBase7(int num) {
    bool flag=(num>=0);
    string res;
    num=abs(num);
    while(num>0){
        res=char(num%7+'0')+res;
        num/=7;
    }
    if(res.size()==0) return "0";
	return flag==true? res:'-'+res;
}
int main(){
	std::cout<<"result:"<<convertToBase7(100)<<std::endl;
	return 0;
}
