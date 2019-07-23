// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long L=1;
        long long mid=0;
        long long result=n;
        while(L<=n){
            mid=(L+n)/2;
            if(isBadVersion(mid)){
                result=min(mid,result);
                n=mid-1;
            }else L=mid+1;
        }
        return result;
    }
};
