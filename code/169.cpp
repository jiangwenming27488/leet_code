 #include<iostream>
 #include<map>
 #include<vector>
 using namespace std; 
 int majorityElement(vector<int>& nums) {
        int size=nums.size();
        map<int,int> _map;
        int sum=0;
        for(int i=0;i<size;++i){
            _map[nums[i]]+=1;
            if(_map[nums[i]]*2>size) sum=nums[i];
    	}
    return sum;
}
int main(){
	vector<int> _vec={2,2,2,2,1,1};
	std::cout<<"majorityElement:"<<majorityElement(_vec)<<std::endl;
	return 0;
}
