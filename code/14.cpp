class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.size()==0) return result;
        string str=strs[0];
        for(int i=1;i<=str.size();++i){
            int j=1;
            for(;j<strs.size();++j){
                if(strs[j].size()<i) break;
                if(strs[j].substr(0,i)==str.substr(0,i)) continue;
                else break;
            }
            if(j==strs.size()){
                result=str.substr(0,i);
            }
        }
        return result;
    }
};
