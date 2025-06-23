class Solution {

    void DFS(vector<vector<int>>& image, int i,int j,int color,int original){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() 
        || image[i][j]==color || image[i][j]!=original)  return ;
        image[i][j]=color;
        DFS(image,i,j+1,color,original);
        DFS(image,i,j-1,color,original);
        DFS(image,i+1,j,color,original);
        DFS(image,i-1,j,color,original);
    }   

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original=image[sr][sc];
        DFS(image,sr,sc,color,original);
        return image;
    }
};