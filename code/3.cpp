 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string res;
        int len=s.size();
        int pos=0;
        int result=0;
        for(int i=0;i<len;++i){
            pos=res.find(s[i]);
            if(pos==-1){
                res+=s[i];
            }else{
                res=res.substr(pos+1,string::npos)+s[i];
            }
            result=max(result,static_cast<int>(res.size()));
        }
        return result;
    }
};

