class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int length=0;
        for(int k=0;k<s.length();++k){
            for(int t=i;t<k;++t){
                if(s[t]==s[k]){
                    length=std::max(length,k-i);
                    i=t+1;
                    break;
                }
            }
        }
        length=std::max(length,(int)(s.length())-i);
        return length;
    }
};