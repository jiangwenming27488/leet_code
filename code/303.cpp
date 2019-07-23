class NumArray {
public:
    NumArray(vector<int> nums) {
        int m=nums.size();
        vec.resize(m,0);
        for(int i=0;i<m;++i){
            if(i==0) vec[0]=nums[0];
            else vec[i]=vec[i-1]+nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0) return vec[j];
        return vec[j]-vec[i-1];
    }
private:
    vector<int> vec;
};
