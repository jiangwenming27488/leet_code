#include<iostream>
using namespace std;
const int maxnumber=0x7fffffff;
const int minnumber=0x80000000;
int myAtoi(string str) {
	int index=0;
	while(index<str.length() && str[index]==' ') ++index;
	bool flag=false;
	string result;
	if(index<str.length()){
		if(str[index]=='-' || str[index]=='+'){
			result+=str[index];
		}else if(str[index]>='0' && str[index]<='9'){
			result+=str[index];
		}else 
			return 0;
	} 
	++index;
	for(;index<str.length();++index){
		if(str[index]>='0' && str[index]<='9'){
			result+=str[index];
		}else{
			break;
		}
	}
	int size=result.size();
	if(size==0) return 0;
	else if(size==1 && result[0]=='-') return 0;
	long long res=atoll(result.c_str());
	if(res>maxnumber) return maxnumber;
	else if(res<minnumber) return minnumber;
	return res;
}
int main(){
	std::cout<<"result:"<<myAtoi("4193 with words")<<std::endl;
	return 0;
}
