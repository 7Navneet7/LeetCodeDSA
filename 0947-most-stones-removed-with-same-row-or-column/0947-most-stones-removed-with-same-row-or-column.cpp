class DSU {
public:
    std::vector<int> parent, size;
    
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }
    
    int findPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }
    
    bool unionBySize(int u, int v) {
        int par_u = findPar(u);
        int par_v = findPar(v);
        if (par_u == par_v) return 0;
        
        if (size[par_u] < size[par_v]) {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        } else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        return 1;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& mat) {
        DSU ds(20002);
        int n=mat.size();
        unordered_set<int>st;
        for(auto &ston:mat){
            int rn=ston[0];
            int cn=ston[1]+10001;
            ds.unionBySize(rn,cn);
            st.insert(rn);st.insert(cn);

        }
        int comp=0;
        for(int node:st){
            if(ds.findPar(node)==node)comp++;
        }
        return n-comp;

    }
};