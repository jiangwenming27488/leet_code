#include<iostream>
#include<vector> 
 int maxProfit(std::vector<int>& prices) {
    int size=prices.size();
    long price=0;
    int value=0;
    for(int i=0;i<size-1;++i){
        for(int j=i+1;j<size;++j){
            value=prices[j]-prices[i];
            if(price<value && value>0) price=value;
        }
    }
    return price;
}
int main(){
	std::vector<int> vec={7,1,5,3,6,4};
	std::cout<<"maxProfit:"<<maxProfit(vec)<<std::endl;
	return 0;
}
