class Solution {
public:
    std::string convert(const std::string& src){
       std::ostringstream res;
       std::copy(src.begin(),src.end(),std::ostream_iterator<char>(res,"*"));
       return res.str();
    }
    string longestPalindrome(string s) {
        std::string str=convert(s);
        int start=0;
        int max_len=0;
        for(int i=0;i<str.length();++i){
            int left=i-1;
            int right=i+1;
            int len=0;
            int index=0;
            if(str[i]!='*'){
                len++;
                index=i;
            }
            while(left>=0 && right<str.length() && (str[left]==str[right])){
                if(str[left]!='*'){
                    index=left; 
                    len+=2;  
                }
                left--;
                right++; 
            }
            if(len>max_len){
                max_len=len;
                start=index/2;
            }
        }
        return s.substr(start,max_len);
    }
};