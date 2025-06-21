class Solution {

    bool check(vector<vector<char>>& board,int row,int col,char target){
        // Row check
        for(int co=0;co<9;co++)    if(board[row][co]==target)   return 0;
        // Col check
        for(int ro=0;ro<9;ro++)    if(board[ro][col]==target)   return 0;
        // Own matrix check:
        int f=(row/3)*3,g=(col/3)*3;
        int lim1=((row/3)*3)+3,lim2=((col/3)*3)+3;
        for(int i=f;i<lim1;i++){
            for(int j=g;j<lim2;j++){
                if(board[i][j]==target){
                    if(row==8 && col==2) cout<<target<<" "<<board[i][j];
                    return 0;
                }
            }
        }
        return 1;
    }

    bool get(vector<vector<char>>& board,int row,int col){
        if(col==9){
            row++;
            col=0;
        }
        if(row==9 && col==0)    return 1;
        if(board[row][col]!='.'){
            if(get(board,row,col+1))    return 1;
            return 0;
        }
        else{
            for(int val=1;val<10;val++){
                char target=char(48+val);
                if(check(board,row,col,target)){
                    board[row][col]=char(48+val);
                    if(get(board,row,col+1))    return 1;
                    board[row][col]='.';
                }
            }
            return 0;
        }
        return 0;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        get(board,0,0);
    }
};