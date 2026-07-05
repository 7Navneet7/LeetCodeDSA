class Solution {
public:
    bool check(int s,vector<vector<int>>&adj,vector<int>&col){
        col[s]=0;
        queue<int>q;q.push(s);
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int nei:adj[cur]){
                if(col[nei]==-1){
                    col[nei]=!col[cur];
                    q.push(nei);
                }
                else if(col[nei]==col[cur]){
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int>col(v,-1);
        for(int i=0;i<v;i++){
            if(col[i]==-1){
                if(!check(i,adj,col))return 0;
            }
        }
        return 1;
    }
};