 #include<iostream>
 #include<stack>
 using namespace std;
 bool isValid(string s) {
    stack<char> ss;
    for(int index=0;index<s.size();++index){
    	if(ss.empty()){
    		ss.push(s[index]);
		}else{
			if(s[index]==']' && ss.top()=='['){
				ss.pop();
			}else if(s[index]=='}' && ss.top()=='{'){
				ss.pop();
			}else if(s[index]==')' && ss.top()=='('){
				ss.pop();
			}else{
				ss.push(s[index]);
			}
		}
    }
    return ss.empty();
}
int main(){
	std::cout<<"isValid:"<<isValid("()")<<std::endl;
	return 0;
}
