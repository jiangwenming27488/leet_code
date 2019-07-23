#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int d=0;
int getMinDistance(string word1,string word2){
	int len1=word1.length();
	int len2=word2.length();
	vector<vector<int> > vec(len1+1,vector<int>(len2+1,0));
	for(int i=0;i<=len1;++i) vec[i][0]=i;
	for(int j=0;j<=len2;++j) vec[0][j]=j;
	for(int i=1;i<=len1;++i){
		for(int j=1;j<=len2;++j){
			d=1;
			if(word1[i-1]==word2[j-1]) d=0;
			vec[i][j]=min(vec[i-1][j-1]+d,min(vec[i][j-1]+1,vec[i-1][j]+1)); 
		}
	}
	return vec[len1][len2];
}
int minDistance(string word1, string word2) {
	return getMinDistance(word1,word2);
}
int main(){
	std::string str1="horse";
	std::string str2="ros";
	std::cout<<"minDisnace:"<<minDistance(str1,str2)<<std::endl;
	return 0;
	
}
