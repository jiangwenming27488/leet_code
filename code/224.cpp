class Solution {
public:
    int getCal(const string& str){
		int index=0;
        int len=str.size();
        int number=0;
        int temp=0;
        while(index<len){
            if(str[index]!='+' && str[index]!='-'){
                temp=str[index]-'0';
                number=number*10+temp;
                ++index;
            }else{
                int j=index+1;
                int nums=0;
                while(j<len){
                    if(str[j]!='+' && str[j]!='-'){
                        temp=str[j]-'0';
                        nums=nums*10+temp;
                        ++j;
                    }else break;
                }
                if(str[index]=='+') number+=nums;
                else number-=nums;
                index=j;
            }
        }
        return number;
	}
    int calculate(string s) {
        int index=0;
        int len=s.size();
        while(index<len){
        	if(s[index]==' '){
        		++index;
				continue;
			}
        	if(s[index]!=')'){
        		ss.push(s[index]);
			}else{
				string temp;
				while(ss.top()!='('){
					temp=ss.top()+temp;
					ss.pop();
				}
				ss.pop();
				temp=to_string(getCal(temp));
                int size=temp.size();
                if(size>0 && temp[0]=='-' && (!ss.empty())){
                        if(ss.top()=='+'){
                            ss.pop();
                            ss.push('-');
                            temp=temp.substr(1);
                        }else if(ss.top()=='-'){
                            ss.pop();
                            ss.push('+');
                            temp=temp.substr(1);
                        } 
                }
				for(int j=0;j<temp.size();++j){
					ss.push(temp[j]);
				}
			}
			++index;
		}
		string result;
		while(!ss.empty()){
			result=ss.top()+result;
			ss.pop();
		}
		return getCal(result);
    }
private:
    stack<char> ss;
};
