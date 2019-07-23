#include<iostream>
#include<set>
bool isHappy(int n) {
    int sum=0;
    std::set<int> record;
    int a=0;
    record.insert(n);
    while(true){
        sum=0;
        while(n){
            a=n%10;
            sum+=a*a;
            n/=10;
        }
        if(sum==1) return true;
        else if(record.find(sum)!=record.end()){
            break;
        }else{
            record.insert(sum);
        }
        n=sum;
    }
    return false;
}
int main(){
	int a=19;
	std::cout<<"a is "<<(isHappy(a)? "":"not ")<<"happy number"<<std::endl;
	return 0;
}
