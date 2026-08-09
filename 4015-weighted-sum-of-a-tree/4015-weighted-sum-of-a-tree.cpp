class Solution {
public:
    using ll=long long;
    long long weightedSum(vector<int>& par, vector<int>& nus) {
        //build adjacency representation O(n)
        //parent -> children
        int n=nus.size();
        int root=-1;
        vector<vector<int>>adj(n);
        for(int i=0;i<par.size();i++){
            //identified the root node
            if(par[i]==-1)root=i;
            else adj[par[i]].push_back(i);
        }
        //dfs to compute depths and max height 
        vector<int>dep(n,0);
        ll m_h=0;
        dep[root]=1;
        auto dfs=[&](auto& self,int u,int depth)->void{
            dep[u]=depth;
            m_h=fmax(m_h,depth);
            for(int v:adj[u])self(self,v,depth+1);
        };
        dfs(dfs,root,1);
        //compute final weighted sum
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=(ll)nus[i]*(m_h-dep[i]+1);
        }
        return ans;
        
    }
};