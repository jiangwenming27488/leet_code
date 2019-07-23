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
		count+=int(num1[index+diff]-'0')+int(num2[index]-'0'); 
		num1[index+diff]=char(count%10+'0'); 
		count/=10;
	}
	for(int index=diff-1;index>=0;--index){
		count+=int(num1[index]-'0');
		num1[index]=char(count%10+'0'); 
		count/=10;
	}
	if(count!=0){
		num1=char(count+'0')+num1;
	}
	return num1;
}
int main(){
	std::cout<<"result:"<<addStrings("9","99")<<std::string(2,'0')<<std::endl;
	return 0;
}
