class Solution {
public:
    void dfs(int cur,vector<vector<int>>&adj,vector<bool>&vis){
        vis[cur]=1;
        for(int nei:adj[cur]){
            if(!vis[nei]){
                dfs(nei,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int v=mat.size();
        vector<vector<int>>adj(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(mat[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int com=0;
        vector<bool>vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                com++;
                dfs(i,adj,vis);
            }
        }
        return com;
    }
};