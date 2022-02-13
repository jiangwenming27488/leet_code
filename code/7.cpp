class Solution {
public:
    int reverse(int x) {
        bool flag=x>0;
        std::string src{std::to_string(std::abs(x))};
        int max_num=std::numeric_limits<int>::max();
        int min_num=std::numeric_limits<int>::min();
        std::reverse(src.begin(),src.end());
        if(std::to_string(min_num)==src && (!flag)){
            return min_num;
        }
        if(check(src,max_num)){
            return 0;
        }
        int res=0;
        for(int i=0;i<src.length();++i){
            res=res*10+(src[i]-'0');
        }
        return (flag ? 1:-1)*res;
    }

private:
    bool check(const std::string& src,int num){
        int count=0;
        int factor=0;
        for(int i=src.length()-1;i>=0;--i){
            factor=count+(src[i]-'0')-num%10;
            if(factor<0){
                count=-1;
            }else{
                count=0;
            }
            num/=10;
        }
        if(num>0){
            return false;
        }
        return count==0;
    }
};