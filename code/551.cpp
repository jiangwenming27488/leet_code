#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
        if(s.find("LLL")!=-1) return false;
        else if(count(s.begin(),s.end(),'A')>1) return false;
        return true;
    }
};
int main(){
	Solution s;
	std::cout<<"result:"<<s.checkRecord("PPPLLL")<<std::endl;
	return 0;
}
