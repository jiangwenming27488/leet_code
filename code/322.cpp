#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
	std::sort(coins.begin(),coins.end());
    int rows=coins.size();
	vector<vector<int>> value(rows,vector<int>(amount+1,-1));
	for(int i=0;i<rows;++i) value[i][0]=0;
	for(int j=0;j<=amount;++j) value[0][j]=j/coins[0];
	for(int idy=1;idy<=amount;++idy){
		for(int idx=1;idx<rows;++idx){
			if(idy<coins[idx]){
				value[idx][idy]=value[idx-1][idy];
			}else{
				value[idx][idy]=min(value[idx][idy-coins[idx]]+1,value[idx-1][idy-coins[idx]]+1);
				value[idx][idy]=min(value[idx][idy],value[idx-1][idy]);
			}
		}
	}
	int count=value[rows-1][amount];
	int row=rows-1;
	int result=count;
	std::cout<<"result:"<<result<<std::endl;
	while(count>0 && row>=0){
		if(amount>=coins[row]){
			amount-=coins[row];
			--count;
		}else --row;
	}
	return amount==0 ? result:-1;
}

int main(){
	std::vector<int> vec={186,419,83,408};
	std::cout<<"result:"<<coinChange(vec,6249)<<std::endl;
	return 0;
}
