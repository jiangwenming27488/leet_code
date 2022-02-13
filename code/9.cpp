class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        std::string origin{std::to_string(x)};
        for(int i=0;i<origin.length()/2;++i){
            if(origin[i]!=origin[origin.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};