class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int counter=0;
                for(int x=max(0,i-1);x<min(i+2,m);x++)
                    for(int y=max(j-1,0);y<min(j+2,n);y++)
                        counter += board[x][y] & 1;
                if(counter==3 || counter-board[i][j]==3)
                    board[i][j] |= 2;
            }
        }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            board[i][j]>>=1;
    }   
};