#include<iostream>
using namespace std;
bool isUgly(int num) {
   while(num){
   		if(num%2==0)
   			num=num>>1;
   		else if(num%3==0){
   			num=num/3;
		}else if(num%5==0){
			num=num/5;
		}else{
			break;
		}
   } 
   return num==1;   
}
int main(){
	std::cout<<"result:"<<isUgly(14)<<std::endl;
	return 0;
}
