#include<iostream>
#include<vector>

using namespace std;
vector<vector<int> > vec;
vector<int> _tmp;
vector<int> path;
vector<int> flag;
void calPer(int index,int number,int k,int pos){
    if(index>=k){
        _tmp.clear();
        for(int i=0;i<k;++i){
            _tmp.emplace_back(path[i]);
        }
        vec.emplace_back(_tmp);
        return;
    }
    for(int i=pos;i<=number;++i){
        if(flag[i-1]==false){
            path[index]=i;
            flag[i-1]=true;
            calPer(index+1,number,k,i+1);
            flag[i-1]=false;
        }
    }
}
vector<vector<int>> combine(int n, int k) {
    vec.clear();
    path.resize(k);
    flag.resize(n);
    calPer(0,n,k,1);
    return vec;
}
int main(){
	int n=4,k=2;
	vec=combine(n,k);
	for(int i=0;i<vec.size();++i){
		std::cout<<"{";
		for(auto& element:vec[i]){
			std::cout<<element<<" ";
		}
		std::cout<<"}"<<std::endl;
	}
	return 0;
}
