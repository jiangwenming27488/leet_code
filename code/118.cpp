class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        for(int index=0;index<numRows;++index){
            if(index==0 || index==1){
                vec.emplace_back(vector<int>(index+1,1));
            }else{
                vector<int> _vec(index+1,1);
                for(int i=1;i<index;++i){
                    _vec[i]=vec[index-1][i-1]+vec[index-1][i];
                }
                vec.emplace_back(_vec);
            }
        }
        return vec;
    }
private:
    vector<vector<int>> vec;
};
