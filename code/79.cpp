class Solution {
public:
    bool check(int m,int n,int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    bool getResult(int index,vector<vector<char>>& board,const string& word,int m,int n,int pos_x,int pos_y){
        if(index>=word.size()) return true;
        if(!check(m,n,pos_x,pos_y) || board[pos_x][pos_y]!=word[index]){
            return false;
        }
        if(!vec[pos_x][pos_y]){
            vec[pos_x][pos_y]=1;
            if(getResult(index+1,board,word,m,n,pos_x+1,pos_y) || getResult(index+1,board,word,m,n,pos_x-1,pos_y)
              || getResult(index+1,board,word,m,n,pos_x,pos_y+1) || getResult(index+1,board,word,m,n,pos_x,pos_y-1)){
                return true;
            }
            vec[pos_x][pos_y]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()||word.empty()) return false;
        int m=board.size();
        int n=board[0].size();
        vec.resize(m,vector<int>(n,0));
        int index=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(getResult(index,board,word,m,n,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    vector<vector<int>> vec;
};
