#include<iostream>
using namespace std;
int hammingWeight(uint32_t n) {
    int count=0;
    for(int index=0;index<32;++index){
        count+=n&1;
        n>>=1;
    }
    return count;
}

