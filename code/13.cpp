class Solution {
public:
    int romanToInt(string s) {
        int nums=0;
        std::map<char,int> letters={
            {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100},
            {'D',500}, {'M',1000}
        };
        for(int i=0;i<s.length();++i){
            switch(s[i]){
                case 'I':{
                    if(i+1<s.length() && (s[i+1]=='V' || s[i+1]=='X')){
                        nums+=(s[i+1]=='V')*4+(s[i+1]=='X')*9;
                        i++;
                    }else{
                        nums+=letters[s[i]];
                    }
                    break;
                }
                case 'X':{
                    if(i+1<s.length() && (s[i+1]=='L' || s[i+1]=='C')){
                        nums+=(s[i+1]=='L')*40+(s[i+1]=='C')*90;
                        i++;
                    }else{
                        nums+=letters[s[i]];
                    }
                    break;
                }
                case 'C':{
                     if(i+1<s.length() && (s[i+1]=='D' || s[i+1]=='M')){
                        nums+=(s[i+1]=='D')*400+(s[i+1]=='M')*900;
                        i++;
                    }else{
                        nums+=letters[s[i]];
                    }
                    break;
                }
                default:{
                    nums+=letters[s[i]];
                }
            }
        }
        return nums;
    }
};