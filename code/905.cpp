class Solution {
public:
    bool judge(const int& number){
        return number%2==1;
    }
    void exchange(int& a,int& b){
        int temp=a;
        a=b;
        b=temp;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        int len=A.size();
        int first=0;
        int last=len-1;
        while(first<last){
            while(first<last && !judge(A[first])){
                ++first;
            }
            while(last>first && judge(A[last])){
                --last;
            }
            
            exchange(A[first],A[last]);
            ++first;
            --last;
        }
        return A;
    }
};
