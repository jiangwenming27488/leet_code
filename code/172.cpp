#include<iostream>
#include<cmath>
int trailingZeroes(int n) {
     int count=0;
	 while(n>0){
	 	count+=n/5; 
	 	n=n/5;
	 }   
	 return count;
}
int main(){
	std::cout<<"trailingZeros:"<<trailingZeroes(10)<<std::endl;
}
