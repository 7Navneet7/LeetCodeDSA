class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int com=0;
        vector<bool>vis(n,0);
        // queue<int>q;q.push(0);
        // while(!q.empty()){
        //     int nod=q.front();q.pop();
        //     for(auto &it:adj[nod]){
        //         if(!vis[])
        //     }
        // }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                com++;
                queue<int>q; q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int nod=q.front();q.pop();
                    for(auto &it:adj[nod]){
                        if(!vis[it]){
                            q.push(it);vis[it]=1;
                        }
                    }
                }
            }
        }
        return com;
    }
};