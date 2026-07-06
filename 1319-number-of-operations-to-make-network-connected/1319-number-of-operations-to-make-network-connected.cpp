    
class DSU{
public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }
    bool unionBySize(int u,int v){
        int par_u=findPar(u);int par_v=findPar(v);
        if(par_u==par_v)return 0;
        if(size[par_u]<size[par_v]){
            parent[par_u]=par_v;
            size[par_v]+=size[par_u];
        }
        else{
            parent[par_v]=par_u;
            size[par_u]+=size[par_v];
        }
        return 1;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& mat) {
        if(mat.size()<n-1)return -1;
        DSU ds(n);
        for(auto &con:mat){
            ds.unionBySize(con[0],con[1]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i)comp++;
        }
        return comp-1;
    }
};