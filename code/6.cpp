class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        std::string result;
        for(int row=0;row<numRows;++row){
            int i=row;
            while(i<s.length()){
                result.push_back(s[i]);
                if(row>0 && row<numRows-1){
                    int idx=i+2*(numRows-1-row);
                    if(idx<s.length()){
                        result.push_back(s[idx]);
                    }
                }
                i+=2*(numRows-1);
            }
        }
        return result;
    }
};