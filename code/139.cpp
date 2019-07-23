class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
};

