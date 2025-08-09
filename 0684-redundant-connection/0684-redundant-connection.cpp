class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        int cnt=0;
        for(auto &it:parent)    it=(cnt++);
    }

    int parentFind(int node){
        if(node == parent[node]) return node;
        return parent[node]=parentFind(parent[node]);
    }

    void unionBySize(int u,int v){
        int ult_u=parentFind(u);
        int ult_v=parentFind(v);
        if(ult_u == ult_v)  return ;
        if(size[ult_u] < size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        } 
        else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int> s;
        for(auto it:edges){
            s.insert(it[0]);
            s.insert(it[1]);
        }
        DisjointSet obj(s.size()+1);
        int pointer=-1;
        // sort(edges.begin(),edges.end());
        for(int i=0;i<edges.size();i++){
            if(obj.parentFind(edges[i][0])!=obj.parentFind(edges[i][1]))
                obj.unionBySize(edges[i][0],edges[i][1]);
            else    pointer=i;
        }
        return edges[pointer]; 
    }
};