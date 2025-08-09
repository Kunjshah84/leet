
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet obj(n);
        int normal_edge=0;
        for(auto it:connections){
            if(obj.parentFind(it[0])!=obj.parentFind(it[1])){
                obj.unionBySize(it[0],it[1]);
                normal_edge++;
            }
        }
        int extraEdges=connections.size()-normal_edge;
        int cnt=0;
        for(int i=0;i<obj.parent.size();i++)    if(i==obj.parent[i])    cnt++;
        cnt--;
        return (cnt>extraEdges) ? -1 : cnt;
    }
};