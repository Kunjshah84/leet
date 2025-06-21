#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // Here the edge is btn the u and v:
        adj[u][v]=1;
        adj[v][u]=1;
        // Here the graph is gonna be the undirected and unweighted graph  


        // And for the weighted graph...
    }
    return 0;
}