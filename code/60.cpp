#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    vector<int> flag;
    string result;
    int index;
private:
    void getResult(int count,int n,string str,int k){
        if(count==n){
            if(++index==k) result=str;
            return;
        }
        for(int idx=0;idx<n;++idx){
            if(result.size()==0){
                if(flag[idx]==0){
                    flag[idx]=1;
                    getResult(count+1,n,str+to_string(idx+1),k);
                    flag[idx]=0;
                }
            }else return;
        }
        return;
    }
public: 
    string getPermutation(int n, int k) {
        index=0;
        flag.resize(n,0);
        string str;
        getResult(0,n,str,k);
        return result;
    }
};
int main(){
	Solution s;
	std::cout<<"result:"<<s.getPermutation(3,3)<<std::endl;
	return 0;
}
