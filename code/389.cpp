#include<algorithm>
#include<iostream>
using namespace std;
char findTheDifference(string s, string t) {
    int size=s.size();
    int number=0;
    for(int index=0;index<size;++index){
        number^=(s[index]^t[index]);
    }
    number^=t[size];
    return char(number);
}

int main(){
	std::cout<<"result:"<<findTheDifference("asdf","asgfd")<<std::endl;
	return 0; 
}
