class Solution {
public:
    int calculate(string s) {
        int len=s.size();
        int index=0,number=0;
    	bool first=true;
        while(index<len){
        	if(s[index]==' '){
        		++index;
        		continue;
			}
			if(compare(s[index])){
				number=number*10+(s[index]-'0');
				++index;
			}else{
				if(first){
					numbers.emplace_back(number);
					first=false;
				}
				int j=index+1;
				int nums=0; 
				while(j<len){
					if(s[j]==' '){
						++j;
						continue;
					}
					if(compare(s[j])){
						nums=nums*10+(s[j]-'0');
						++j;
					}else break;
				}
				if(s[index]=='*' || s[index]=='/'){
					int left=*numbers.rbegin();
					if(s[index]=='*') *numbers.rbegin()=left*nums;
					else *numbers.rbegin()=left/nums;
				}else{
					numbers.emplace_back(nums);
					flags.emplace_back(s[index]);
				}
				index=j;
			}
		}
        if(numbers.size()==0) return number;
		int result=*numbers.begin();
		for(int i=0;i<flags.size();++i){
			if(flags[i]=='+'){
				result=result+numbers[i+1];
			}else {
				result=result-numbers[i+1];
			}
		}
		return result;
    }
private:
	vector<int> numbers;
	vector<char> flags;
	bool compare(char ch){
		if(ch!='+' && ch!='-' && ch!='*' && ch!='/') return true;
		return false;
	}
};
