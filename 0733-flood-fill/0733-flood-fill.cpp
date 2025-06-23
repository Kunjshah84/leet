class Solution {

    void DFS(vector<vector<int>>& image,vector<vector<int>>& visited,
    int i,int j,int color,int original){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || visited[i][j]
        || image[i][j]!=original)  return ;
        visited[i][j]=1;
        image[i][j]=color;
        DFS(image,visited,i,j+1,color,original);
        DFS(image,visited,i,j-1,color,original);
        DFS(image,visited,i+1,j,color,original);
        DFS(image,visited,i-1,j,color,original);
    }   

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(),vector<int> (image[0].size(),0));
        int original=image[sr][sc];
        DFS(image,visited,sr,sc,color,original);
        return image;
    }
};