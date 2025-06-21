class Solution {

        bool get(vector<vector<char>>& board, string &word,int i,int j,int ind){
            if(ind==word.size())    return 1;
            if(i<0 || j<0 || i>=board.size() || j>=board[0].size() 
            || word[ind]!=board[i][j])  return 0;
            int temp=board[i][j];
            board[i][j]='#';//Picked the index;
            bool v1=get(board,word,i+1,j,ind+1);
            bool v2=get(board,word,i-1,j,ind+1);
            bool v3=get(board,word,i,j+1,ind+1);
            bool v4=get(board,word,i,j-1,ind+1);
            board[i][j]=temp;
            return v1 || v2 || v3 || v4;
        }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)  
                if(board[i][j]==word[0] && get(board,word,i,j,0))  return 1;
        return 0;
    }
};