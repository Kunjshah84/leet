class Solution {

    vector<vector<int>> rotate(vector<vector<int>>& grid){
        vector<vector<int>> newgrid(grid[0].size(),vector<int> (grid.size()));
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                newgrid[j][grid.size()-i-1]=grid[i][j];
        return newgrid;
    }

    int getarea(int sr,int er,int sc,int ec,vector<vector<int>> &grid){
        int minr=grid.size();  
        int maxr=-1;
        int minc=grid.size();
        int maxc=-1;
        bool flg=1;
        for(int i=sr;i<er;i++)
            for(int j=sc;j<ec;j++){
                if(grid[i][j]){
                    minr=min(minr,i);
                    maxr=max(maxr,i);
                    minc=min(minc,j);
                    maxc=max(maxc,j);
                    flg=0;
                }
            } 
        if(flg) return 0;
        return (maxr-minr+1)*(maxc-minc+1);
    }

    void operation(vector<vector<int>>& grid,int &ans){
        int n=grid.size();
        int m=grid[0].size();
        for(int row=1;row<n;row++)
            for(int col=1;col<m;col++){
                int top=getarea(0,row,0,m,grid);
                int botleft=getarea(row,n,0,col,grid);
                int botright=getarea(row,n,col,m,grid);
                ans=min(ans,(top+botleft+botright));
                int bot=getarea(row,n,0,m,grid);
                int topleft=getarea(0,row,0,col,grid);
                int topright=getarea(0,row,col,m,grid);
                ans=min(ans,(bot+topleft+topright));
            }
        for(int split1=1;split1<n;split1++)
            for(int split2=split1+1;split2<n;split2++){
                int first=getarea(0,split1,0,m,grid);
                int second=getarea(split1,split2,0,m,grid);
                int third=getarea(split2,n,0,m,grid);
                ans=min(ans,(first+second+third));
            }
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        operation(grid,ans);
        vector<vector<int>> newgrid=rotate(grid);
        operation(newgrid,ans);
        return ans;
    }
};