#include<iostream> 
#include<vector>
#include<cmath>
using namespace std;
int findComplement(int num) {
    int sum=0;
    vector<int> vec;
    while(num){
        vec.push_back((num%2+1)%2);
        num=num>>1;
    }
    int size=vec.size();
    for(int i=0;i<size;++i){
        sum+=pow(2,i)*vec[i];
    }
    return sum;
}
int main(){
	cout<<"findComplement:"<<findComplement(2)<<endl;
	return 0;
}
