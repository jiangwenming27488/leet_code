class Solution {
public:
    bool judge(int number,int index){
        bool a=number%2==0 && index%2==0;
        bool b=number%2==1 && index%2==1;
        return a||b;
    }
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len=A.size();
        int left=0;
        int right=len-1;
        while(left<right){
            while(left<right && judge(A[left],left)){
                ++left;
            }
            int pos=left+1;
            while(pos<=right)
            {
                if(judge(A[pos],pos) || (pos%2+left%2)!=1){
                    ++pos;
                }
                else{
                    swap(A[left],A[pos]);
                    ++left;
                    break;
                }
            }
        }
        return A;
    }
};
