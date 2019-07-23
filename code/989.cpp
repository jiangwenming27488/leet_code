class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int len=A.size();
        int number=0;
        for(int i=len-1;i>=0;--i){
            number+=A[i]+K%10;
            res.emplace_back(number%10);
            number/=10;
            K/=10;
        }
        while(K!=0){
            number+=K%10;
            res.emplace_back(number%10);
            number/=10;
            K/=10;
        }
        if(number!=0) res.emplace_back(number);
        return vector<int>(res.rbegin(),res.rend());
    }
};
