class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> supporter(board.size(),vector<int>(board[0].size(),0));
        queue<pair<int,int>> q;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if((!i || !j || i==board.size()-1 
                || j==board[0].size()-1) && board[i][j]=='O'){
                    supporter[i][j]=1;
                    q.push({i,j});
                }
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            vector<int> r={-1,+1,0,0};
            vector<int> c={0,0,+1,-1};
            for(int i=0;i<4;i++){
                int nr=temp.first+r[i];
                int nc=temp.second+c[i];
                if(nr>0 && nc>0 && nr<board.size() && nc<board[0].size() && !supporter[nr][nc] && board[nr][nc]=='O'){
                    q.push({nr,nc});
                    supporter[nr][nc]=1;
                }
            }
        }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='O' && !supporter[i][j])    
                    board[i][j]='X';
    }
};