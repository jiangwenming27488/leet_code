 #include<iostream>
 #include<vector>
 #include<cmath>
 using namespace std;
 vector<int> twoSum(vector<int>& numbers, int target) {
    int size=numbers.size();
    int l=0;
    int r=size-1;
    while(l<r){
        if(numbers[l]+numbers[r]==target){
            return vector<int>({l+1,r+1});
        }else if(numbers[l]+numbers[r]<target){
            ++l;
        }else --r;
    }
    return vector<int>();
}
int main(){
	std::vector<int> vec={2,7,11,15};
	vector<int> _vec=twoSum(vec,9);
	std::cout<<"twoSum(9):{";
	for(auto& element:_vec){
		std::cout<<element<<" ";
	}
	std::cout<<"}"<<std::endl;
	return 0;
}
