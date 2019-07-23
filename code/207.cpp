#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int> vec;
    vec.resize(numCourses);
	int size=prerequisites.size();
    for(int i=0;i<size;++i){
        vec[prerequisites[i].first]++;
    }
    deque<int> degree;
    for(int i=0;i<numCourses;++i){
    	if(vec[i]==0){
    		degree.emplace_back(i);
		}
	} 
	while(!degree.empty()){
		int index=*degree.begin();
        for(int j=0;j<size;++j){
        	if(prerequisites[j].second==index){
        		--vec[prerequisites[j].first];
        		if(vec[prerequisites[j].first]==0){
        			degree.emplace_back(prerequisites[j].first);
				}
			}
		}
		degree.pop_front();
	}
	return std::count(vec.begin(),vec.end(),0)==numCourses; 
}
int main(){
	vector<pair<int,int> > vec={{1,0}};
	std::cout<<"canFinsh:"<<canFinish(2,vec)<<std::endl;
	return 0; 
} 
