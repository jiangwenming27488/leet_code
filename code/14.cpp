class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string res;
        for(int i=0;i<strs[0].length();++i){
            bool flag=false;
            for(auto const& str:strs){
                if(str.length()<(i+1) || (str[i]!=strs[0][i])){
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }else{
                res.push_back(strs[0][i]);
            }
        }
        return res;
    }
};