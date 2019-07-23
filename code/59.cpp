class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return vector<vector<int>>();
        vector<vector<int>> vec(n,vector<int>(n,0));
        int rowstart=0;
        int rowend=n-1;
        int colstart=0;
        int colend=n-1;
        int count=1;
        int number=1;
        while(rowstart<=rowend && colstart<=colend){
            if((count%4)==1){
                int idx=colstart;
                while(idx<=colend){
                    vec[rowstart][idx]=number++;
                    ++idx;
                }
                ++rowstart;
            }else if((count%4)==2){
                int idx=rowstart;
                while(idx<=rowend){
                    vec[idx][colend]=number++;
                    ++idx;
                }
                --colend;
            }else if((count%4)==3){
                int idx=colend;
                while(idx>=colstart){
                    vec[rowend][idx]=number++;
                    --idx;
                }
                --rowend;
            }else{
                int idx=rowend;
                while(idx>=rowstart){
                    vec[idx][colstart]=number++;
                    --idx;
                }
                ++colstart;
            }
            ++count;
        }
        return vec;
    }
};
