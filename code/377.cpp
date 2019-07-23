 #include<iostream>
 #include<vector>
 #include<list>
 #include<algorithm> 
 using namespace std;
 vector<vector<int> > vec;
 vector<int> path;
 vector<int> _tmp;
 void calcombinationSum4(vector<int>& nums,int sum,int target){
    if(sum>=target){
        if(sum==target){
        	_tmp.clear();
        	for(int i=0;i<path.size();++i){
        		_tmp.push_back(path[i]);
			}
			sort(_tmp.begin(),_tmp.end());
        	if(find(vec.begin(),vec.end(),_tmp)==vec.end())
				vec.emplace_back(path);
		}
		return ;
    }
    for(int i=0;i<nums.size();++i){
    	path.push_back(nums[i]);
    	calcombinationSum4(nums,sum+nums[i],target);
    	path.pop_back();
	}
}
int combinationSum4(vector<int>& nums, int target) {
    calcombinationSum4(nums,0,target);
    return vec.size();
}
int main(){
	std::vector<int> _vec={4,2,1};
	int target=32;
	std::cout<<"result:"<<combinationSum4(_vec, target)<<std::endl;
	for(int i=0;i<vec.size();++i){
    	std::cout<<"{";
    	for(const auto& element:vec[i]){
    		std::cout<<element<<" ";
		}
		std::cout<<"}"<<std::endl;
	}
	return 0;
} 
