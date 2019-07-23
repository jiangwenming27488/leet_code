 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int m_start=0;
		int m_end=m-1;
        int n_start=0;
		int n_end=n-1;
        int count=1;
        vector<int> result;
        while(m_start<=m_end && n_start<=n_end){
            if((count%4)==1){
                int idx=n_start;
                while(idx<=n_end){
                    result.emplace_back(matrix[m_start][idx]);
                    ++idx;
                }
                ++m_start;
            }else if((count%4)==2){
                int idx=m_start;
                while(idx<=m_end){
                    result.emplace_back(matrix[idx][n_end]);
                    ++idx;
                }
                --n_end;
            }else if((count%4)==3){
                int idx=n_end;
                while(idx>=n_start){
                    result.emplace_back(matrix[m_end][idx]);
                    --idx;
                }
                --m_end;
            }else{
                int idx=m_end;
                while(idx>=m_start){
                    result.emplace_back(matrix[idx][n_start]);
                    --idx;
                }
                ++n_start;
            }
            ++count;
        }
        return result;
    }
};
