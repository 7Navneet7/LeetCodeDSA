class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edg, int dt) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)dist[i][i]=0;
        for(auto &ed:edg){
            int u=ed[0],v=ed[1],w=ed[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e9 && dist[k][j]!=1e9){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int ans=-1;
        int mnc=n;
        for(int i=0;i<n;i++){
            int cnc=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=dt)cnc++;
            }
            if(cnc<=mnc){
                mnc=cnc;
                ans=i;
            }
        }
        return ans;
    }
};