#include<iostream>
#include<algorithm>
using namespace std;
string addStrings(string num1, string num2) {
	int diff=num1.size()-num2.size();
    if(diff<0){
    	std::swap(num1,num2); 
    	diff=-diff;
	}
	int count=0;
	for(int index=num2.size()-1;index>=0;--index){
		count+=(num1[index+diff]-'0')+(num2[index]-'0'); 
		num1[index+diff]=count%10+'0';
		count/=10;
	}
	for(int index=diff-1;index>=0;--index){
		count+=(num1[index]-'0');
		num1[index]=count%10+'0';
		count/=10;
	}
	if(count!=0){
		num1=char(count+'0')+num1;
	}
	return num1;
}
string singleMultiply(int number,string num2){ 
	int count=0;
    for(int index=num2.size()-1;index>=0;--index){
    	count+=number*int(num2[index]-'0');
    	num2[index]=count%10+'0';
    	count/=10;
	}   
	if(count!=0){
		num2=char(count+'0')+num2;
	}
	return num2;
}
string multiply(string num1, string num2) {
    int size=num1.size();
    string result;
    for(int index=size-1;index>=0;--index){
		result=addStrings(singleMultiply(int(num1[index]-'0'),num2)+string(size-1-index,'0'),result);  
        if(count(result.begin(),result.end(),'0')==result.size()){
            result="0";
        }      
    }
    return result;
}
int main(){
	std::cout<<"result:"<<multiply("123","456")<<std::endl;
	return 0;
}
