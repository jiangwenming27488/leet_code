#include<iostream>
#include<vector>
using namespace std;
int minCostClimbingStairs(vector<int>& costs) {
    int size=costs.size();
    vector<int> sum(size,0);
    sum[0]=costs[0];
    sum[1]=costs[1];
    for(int index=2;index<size;++index){
        sum[index]=min(sum[index-1],sum[index-2])+costs[index];
    }
    return min(sum[size-1],sum[size-2]);
}
int main(){
	std::vector<int> vec={1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	std::cout<<"min:"<<minCostClimbingStairs(vec)<<std::endl;
	return 0;
}
