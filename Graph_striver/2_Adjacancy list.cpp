#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // Here the edge is btn the u and v:
        adj[u].push_back(v);
        adj[v].push_back(u);
        // Here the graph is gonna be the undirected and unweighted graph  
        // This is gonna take the time complexity of O(2*E):


        // Now if there is an edge between u and v they give us u v(u--->v):
        // so we just need to do the adj[u].push_back(v);
        // And for this the space complexit O(e);
        
        
        // And here in the case of the weighted graph we have to initialize the vectore like this:
        // vector<pair<int,int>> adj[n+2];
    }
    return 0;
}