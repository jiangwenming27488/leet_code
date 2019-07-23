 #include<iostream>
 #include<algorithm>
 using namespace std;
 int numJewelsInStones(string J, string S) {
    int result=0;
    for(int index=0;index<J.size();++index){
        result+=count(S.begin(),S.end(),J[index]);      
    }
    return result;
}

int main(){
	std::string J="aA";
	std::string S="aAAbbbb";
	std::cout<<"result:"<<numJewelsInStones(J,S)<<std::endl;
	return 0;
}
