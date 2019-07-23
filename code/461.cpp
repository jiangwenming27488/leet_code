#include<iostream>
int hammingDistance(int x, int y) {
        int number=x^y;
        int count=0;
        while(number){
            ++count;
            number=number&(number-1);
        }
        return count;
}
int main(){
	int a=1;
	int b=2;
	std::cout<<"hanming distance:"<<hammingDistance(a,b)<<std::endl;
}
