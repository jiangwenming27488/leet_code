#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
int arr[100000]={0};
int number[100000]={0};
vector<int> vec;
deque<int> zero;
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    int size=prerequisites.size();
    for(int i=0;i<size;++i){
    	arr[prerequisites[i].first]++;
	}
	for(int i=0;i<numCourses;++i){
		if(arr[i]==0){
			zero.emplace_back(i);
		}
	}
	int index=0;
	while(!zero.empty()){
		index=zero[0];
		for(int j=0;j<size;++j){
			if(prerequisites[j].second==index){
				if((--arr[prerequisites[j].first])==0){
					zero.emplace_back(prerequisites[j].first);
				}
			}
		}
		vec.emplace_back(index);
		zero.pop_front();
	}
	if(vec.size()==numCourses){
		return vec;
	}
	return vector<int>();
}
int main(){
	std::vector<std::pair<int,int> > _vec;
	vec=findOrder(3,_vec);
	std::cout<<"{";
	for(auto& element:vec){
		std::cout<<element<<" ";
	}
	std::cout<<"}"<<std::endl;
	return 0;
}
