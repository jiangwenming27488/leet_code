 #include<iostream>
 #include<vector>
 using namespace std;
 vector<int> _vec;
 int maxSubArray(vector<int>& nums) {
    int sum=0;
    int return_sum=0;
    for(int i=0;i<nums.size();++i){
        if(sum+nums[i]>=nums[i]){
            sum+=nums[i];
        }else{
            sum=nums[i];
        }
        if(return_sum<sum) return_sum=sum;
    }
    return return_sum;
}
int main(){
	std::vector<int> vec={-2,1,-3,4,-1,2,1,-5,4};
	std::cout<<"maxSubArray:"<<maxSubArray(vec)<<std::endl;
	return 0;
}
