 #include<iostream>
 #include<vector>
 #include<algorithm> 
 using namespace std;
 vector<vector<int> > vec;
 vector<int> path;
 vector<int> _tmp;
 void calcombinationSum(vector<int>& nums,int sum,int target,int pos){
    if(sum>=target){
        if(sum==target){
			vec.emplace_back(path);
		}
		return ;
    }
    for(int i=pos;i<nums.size();++i){
    	path.push_back(nums[i]);
    	calcombinationSum(nums,sum+nums[i],target,i);
    	path.pop_back();
	}
}
int combinationSum(vector<int>& nums, int target) {
	sort(nums.begin(),nums.end());
    calcombinationSum(nums,0,target,0);
    return vec.size();
}
int main(){
	std::vector<int> _vec={2,3,6,7};
	int target=7;
	std::cout<<"result:"<<combinationSum(_vec, target)<<std::endl;
	for(int i=0;i<vec.size();++i){
    	std::cout<<"{";
    	for(const auto& element:vec[i]){
    		std::cout<<element<<" ";
		}
		std::cout<<"}"<<std::endl;
	}
	return 0;
} 
