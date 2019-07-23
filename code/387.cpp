class Solution {
public:
    int firstUniqChar(string s) {
        set<char> _set;
        for(int i=0;i<s.size();++i){
            if(_set.find(s[i])!=_set.end()) continue;
            if(count(s.begin(),s.end(),s[i])==1) return i;
            else{
                _set.insert(s[i]);
            }
        }
        return -1;
    }
};
