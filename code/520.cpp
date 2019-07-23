#include<iostream>
using namespace std;
bool detectCapitalUse(string word) {
    int count[2]={0,0};
    for(int index=0;index<word.size();++index){
        if(word[index]>='a' && word[index]<='z'){  
            count[0]++;
        }else{
            count[1]++;
        }
    }
    if(count[1]>0 && count[0]>0){
        return word[0]>='A' && word[0]<='Z' && count[1]==1;
    }
    return count[1]==0 || count[0]==0;
}
int main(){
	std::cout<<"result:"<<detectCapitalUse("USA")<<std::endl;
	return 0;
}
