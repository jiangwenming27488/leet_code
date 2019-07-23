#include<iostream>
#include<algorithm>
using namespace std;
bool check(char ch){
    return (ch>='a' && ch<='z' )||( ch>='0' && ch<='9');
}
bool isPalindrome(string s) {
    int size=s.size();
    int left=0;
    int right=size-1;
    while(left<=right){
        if(!check(tolower(s[left]))){
            ++left;
        }else if(!check(tolower(s[right]))){
            --right;
        }else{
            if(!(tolower(s[left])==tolower(s[right])))
            	return false;
            left++;
            right--;
        }
    }
    return true;
}
int main(){
	std::string str="race a car";
	std::cout<<"result:"<<isPalindrome(str)<<std::endl;
	return 0;
}
