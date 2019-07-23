#include<iostream>
#include<algorithm>
using namespace std;
int strStr(string haystack, string needle) {
    return haystack.find(needle);
}
int main(){
	std::cout<<"result:"<<strStr("asdfg","dfg")<<std::endl;
	return 0;
}
