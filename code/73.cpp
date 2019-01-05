class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> vec;
        for(int index=0;index<matrix.size();++index){
            for(int idx=0;idx<matrix[index].size();++idx){
                if(matrix[index][idx]==0){
                    vec.insert({index,idx});
                }
            }
        }
        for(auto element:vec){
            for(int index=0;index<matrix[element.first].size();++index){
                matrix[element.first][index]=0;
            }
            for(int index=0;index<matrix.size();++index){
                matrix[index][element.second]=0;
            }
        }
    }
};
