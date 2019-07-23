class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        vector<vector<int>> vec(rows,vector<int>(rows,0));
        for(int i=0;i<rows;++i){
            for(int j=0;j<rows;++j){
                if(vec[i][j]==0){
                    swap(matrix[j][rows-1-i],matrix[i][j]);
                    vec[i][j]==1;
                    vec[j][rows-1-i]=1;
                }
            }
        }
    }
};
