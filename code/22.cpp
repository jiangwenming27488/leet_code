class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::stack<char> s;
        std::string res;
        this->generate(0,n,0,s,res);
        return this->results;
    }



private:
    void generate(int left,int target,int right,std::stack<char>& s,std::string& res){
        if(left==target && right==target){
            if(s.empty()){
                this->results.push_back(res);
            }
            return;
        }
        for(int i=0;i<msg.length();++i){
            if(msg[i]=='('){
                if(left<target){
                    s.push('(');
                    res.push_back('(');
                    generate(left+1,target,right,s,res);
                    res.pop_back();
                    s.pop();
                }
            }else if(msg[i]==')'){
                if(right<target){
                     if(!s.empty() && s.top()=='('){
                        s.pop();
                        res.push_back(')');
                        generate(left,target,right+1,s,res);
                        res.pop_back();
                        s.push('(');
                    }
                }
            }
        }
    }
private:
    std::vector<std::string> results;
    std::string msg="()";
};