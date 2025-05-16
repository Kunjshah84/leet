class Solution {

    bool get(vector<vector<char>>& board, string &word,int r,int col,
    string temp,int ind,map<pair<int,int>,int> &m){
        if(ind>=word.size() || r<0 || col<0 || 
        r>=board.size() || col>=board[0].size() 
        || board[r][col]!=word[ind] || m[{r,col}])    return 0;
        temp+=(board[r][col]);
        if(temp.size()>word.size()) return 0;
        if(temp==word)  return 1;
        m[{r,col}]=1;
        if(get(board,word,r,col-1,temp,ind+1,m) 
        || get(board,word,r,col+1,temp,ind+1,m) 
        || get(board,word,r+1,col,temp,ind+1,m)
        || get(board,word,r-1,col,temp,ind+1,m))    return 1;
        m[{r,col}]=0;
        return 0;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0)  return 0;
        map<pair<int,int>,int> m;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]==word[0] && get(board,word,i,j,"",0,m)) return 1;
        return 0;
    }
};