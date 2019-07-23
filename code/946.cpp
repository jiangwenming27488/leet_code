#include<iostream>
#include<vector>
#include<stack>
using namespace std;
stack<int> s;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int count=0;
    int size=pushed.size();
    int size1=popped.size();
	if(size==0 && size1==0) return true;
	else if(size==0) return false;
	else if(size1==0) return false;
	int index=0; 
    while(index<=size){
    	if(!s.empty() && s.top()==popped[count]){
    		s.pop();
    		++count;
		}else{
			if(index!=size)
	     		s.push(pushed[index]);
        	++index;
		}
    }
    return s.empty();
}
int main(){
	std::vector<int> push={1,2,3,4,5};
	std::vector<int> pop={4,5,3,2,1};
	std::cout<<"result:"<<validateStackSequences(push,pop)<<std::endl;
	return 0;
}
