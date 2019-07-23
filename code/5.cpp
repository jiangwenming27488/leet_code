#include<iostream>
#include<vector>
using namespace std;
vector<char> vec;
string result;
int left1,right1;
string str;
string leftstr,rightstr;
string longestPalindrome(string s) {
    int index=0;
    int size=s.size();
	for(index=0;index<size;++index){
		vec.emplace_back('#');
		vec.emplace_back(s[index]);
	}
	vec.emplace_back('#');
    int idx=0;
	for(index=1;index<2*size+1;index+=1){
        idx=index%2+1;
		left1=index-idx;
		right1=index+idx;
		leftstr="";
        rightstr="";
		while(left1>=0 && right1<vec.size()){
			if(vec[left1]==vec[right1]){
				leftstr=vec[left1]+leftstr;
                rightstr=rightstr+vec[right1];
				left1-=2;
				right1+=2;
			}else{
				break;
			}
		}
        if(idx==1)
            str=leftstr+rightstr;
        else str=leftstr+vec[index]+rightstr;
		if(str.size()>result.size()){
			result=str;
		}
	}
	return result;
}
int main(){
	std::cout<<"result:"<<longestPalindrome("cbbd")<<std::endl;
	return 0;
}
