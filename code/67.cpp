#include<iostream>
using namespace std;
 string addBinary(string a, string b) {
    string result;
    int i=a.size()-1;
    int j=b.size()-1;
    int number=0;
    while(i>=0 && j>=0){
    	result=char((a[i]-'0'+b[j]-'0'+number)%2+'0')+result;
        number=(a[i]-'0'+b[j]-'0'+number)/2;
        --i;
        --j;
    }
    while(i>=0){
    	result=char((a[i]-'0'+number)%2+'0')+result;
        number=(a[i]-'0'+number)/2; 
        --i;
    }
    while(j>=0){
    	result=char((b[j]-'0'+number)%2+'0')+result;
        number=(b[j]-'0'+number)/2;
        --j;
    }
    return number==1? "1"+result:result;
}
int main(){
	std::cout<<"result:"<<addBinary("1010","1011")<<std::endl;
	return 0;
}
