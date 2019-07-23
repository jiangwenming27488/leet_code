class Solution {
public:
    int searchLeft(vector<int>& nums,int target,int a,int b){
        int mid=0;
        int aim=10000000;
        while(a<=b){
            mid=(a+b)/2;
            if(nums[mid]==target){
                aim=min(mid,aim);
            }
            if(nums[mid]>=target){
                b=mid-1;
            }else a=mid+1;
        }
        return aim==10000000? -1:aim;
    }
    int searchRight(vector<int>& nums,int target,int a,int b){
        int mid=0;
        int aim=-1;
        while(a<=b){
            mid=(a+b)/2;
            if(nums[mid]==target){
                aim=max(mid,aim);
            }
            if(nums[mid]>target){
                b=mid-1;
            }else a=mid+1;
        }
        return aim;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        int L=0;
        int R=len-1;
        int mid=0;
        vector<int> vec(2,-1);
        while(L<=R){
            mid=(L+R)/2;
            if(nums[mid]==target){
                vec[0]=vec[1]=mid;
                int a=searchLeft(nums,target,L,mid-1);
                if(a!=-1) vec[0]=a;
                int b=searchRight(nums,target,mid+1,R);
                if(b!=-1) vec[1]=b;
                break;
            }
            else if(nums[mid]>target) R=mid-1;
            else L=mid+1;
        }
        return vec;
        
    }
};
