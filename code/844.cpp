#include<iostream>
#include<stack>
using namespace std;
string getStr(const string& str){
	stack<char> ss;
	for(int index=0;index<str.size();++index){
		if(str[index]!='#'){
			ss.push(str[index]);
		}else{
			if(!ss.empty()){
				ss.pop();
			}
		}
	}
	string sstr;
	while(!ss.empty()){
		sstr=ss.top()+sstr;
		ss.pop(); 
	}
	return sstr;
}
bool backspaceCompare(string S, string T) {
	string str_S=getStr(S);
	string str_T=getStr(T);
	return str_S==str_T;
}
int main(){
	std::cout<<"result:"<<backspaceCompare("a#c","b")<<std::endl;
	return 0;
}
