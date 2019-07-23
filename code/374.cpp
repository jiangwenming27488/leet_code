// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long L=1,R=n;
        long long result=n;
        long long mid=0;
        while(L<=R){
            mid=(L+R)/2;
            if(guess(mid)==0){
                result=mid;
                break;
            }
            else if(guess(mid)==1) L=mid+1;
            else R=mid-1;
        }
        return result;
    }
};
