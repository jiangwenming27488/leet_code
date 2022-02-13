class Solution {
public:
    int myAtoi(string s) {
        long long number=0;
        int i=0;
        //remove space
        while(i<s.length()){
            if(s[i]==' '){
                i++;
            }else{
                break;
            }
        }
        long long max_value=std::numeric_limits<int>::max();
        long long min_value=std::numeric_limits<int>::min();
        bool is_neg=false;
        if(i<s.length()){
            if(s[i]=='-'){
                i++;
                is_neg=true;
            }else if(s[i]=='+'){
                i++;
            }
            while(i<s.length() &&(s[i]>='0') && (s[i]<='9') && (number<max_value+1)){
                number=number*10+(s[i]-'0');
                i++;
            }
        }
        if(is_neg){
            number=-1*number;
        }
        if(number>max_value){
            return max_value;
        }else if(number<=min_value){
            return min_value;
        }
        return number;
    }
};