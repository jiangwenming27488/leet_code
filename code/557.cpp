class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0) return s;
        int start=0;
        int end=0;
        char temp;
        s+=" ";
        for(int i=0;i<s.size();++i){
            if(s[i]!=' '){
                ++end;
            }else{
                for(int index=0;index<=(end-1-start)/2;++index){
                    temp=s[index+start];
                    s[index+start]=s[end-1-index];
                    s[end-1-index]=temp;
                }
                start=end+1;
                end=end+1;
            }
        }
        return s.substr(0,s.size()-1);
    }
};
