class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMatrix(n,vector<int> (n,1e9));
        for(auto it:edges){
            adjMatrix[it[0]][it[1]]=it[2];
            adjMatrix[it[1]][it[0]]=it[2];
        }
        for(int ver=0;ver<n;ver++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(!(i==j || adjMatrix[i][ver]==1e9 || 
                    adjMatrix[ver][j]==1e9 || 
                    adjMatrix[i][j] <= (adjMatrix[i][ver] + adjMatrix[ver][j])))
                        adjMatrix[i][j] = adjMatrix[i][ver] + adjMatrix[ver][j];
        int minCity=INT_MAX;
        int maxCity=INT_MIN;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++)
                if(adjMatrix[i][j] <= distanceThreshold)    cnt++;
            if(cnt<minCity){
                minCity=cnt;
                maxCity=i;
            }
            else if(cnt==minCity && i>maxCity)  maxCity=i;   
        }
        return maxCity; 
    }
};