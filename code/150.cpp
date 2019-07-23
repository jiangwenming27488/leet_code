#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    long long getNumber(long long a,long long b,const string& idx){
        if(idx=="+") 
			return a+b;
        else if(idx=="-") 
			return a-b;
        else if(idx=="*") 
			return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        int a=0;
        int b=0;
        for(int index=0;index<tokens.size();++index){
            if(tokens[index]=="+" || tokens[index]=="-" || tokens[index]=="*" || tokens[index]=="/"){
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                s.push(getNumber(b,a,tokens[index]));
            }else{
                s.push(atoi(tokens[index].c_str()));
            }
        }
        return s.top();
    }
private:
    stack<int> s;
};
int main(){
	std::vector<std::string> vec={"2", "1", "+", "3", "*"};
	Solution s;
	std::cout<<"result:"<<s.evalRPN(vec)<<std::endl;
	return 0;
}
