#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool word(string s, vector<string>& wordDict) {
        set<int> vec;
        vec.insert(0);
        int len=s.size();
        for(int index=0;index<len;++index){
            for(auto& pos:vec){
                if(find(wordDict.begin(),wordDict.end(),s.substr(pos,index-pos+1))!=wordDict.end()){
                    vec.insert(index+1);
                }
            }
        }
        return *vec.rbegin()==len;
    }
    void getResult(string left,int leftlen,string add,vector<string>& wordDict,string target){
        if(leftlen<=0){
            string str=add.substr(0,add.size()-1);
            if(leftlen==0){
                vec.emplace_back(str);
            }
            return;
        }
        for(int i=0;i<wordDict.size();++i){
            int len=wordDict[i].size();
            if(leftlen<len) continue;
            bool flag=(left.substr(0,len)==wordDict[i]);
            if(flag){
                getResult(left.substr(len),leftlen-len,add+wordDict[i]+" ",wordDict,target);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(!word(s,wordDict)) return vec;
        string add;
        int leftlen=s.size();
        getResult(s,leftlen,add,wordDict,s);
        return vec;
    }
private:
    vector<string> vec;
};
int main(){
	std::string s="catsanddog";
	std::vector<std::string> vec={"cat","cats","and","sand","dog"};
	Solution ss;
	vector<std::string> result=ss.wordBreak(s,vec);
	std::cout<<"result:[";
	for(auto  & ele:result){
		std::cout<<ele<<std::endl;
	} 
	std::cout<<"]"<<std::endl;
	return 0;
}
