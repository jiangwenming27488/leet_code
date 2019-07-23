#include<iostream>
#include<vector>
using namespace std;
int l;
int r;
void swap(char& ch1,char& ch2){
    ch1=ch1+ch2;
    ch2=ch1-ch2;
    ch1=ch1-ch2;
}
void reverseString(vector<char>& s) {
    l=0;
    r=s.size()-1;
    while(l<r){
        swap(s[l],s[r]);
        ++l;
        --r;
    }
}
int main(){
	std::vector<char> vec={'h','e','l','l','o'};
	reverseString(vec);
	std::cout<<"{";
	for(auto& element:vec){
		std::cout<<element<<" ";
	}
	std::cout<<"}"<<std::endl;
	return 0;
}
