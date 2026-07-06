class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n=mat.size();int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto [ce,cell]=pq.top();pq.pop();
            int r=cell.first;int c=cell.second;
            if(r==n-1 && c==m-1)return dist[r][c];
            if(ce>dist[r][c])continue;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int scost=abs(mat[nr][nc]-mat[r][c]);
                    int ne=max(ce,scost);
                    if(ne<dist[nr][nc]){
                        dist[nr][nc]=ne;
                        pq.push({ne,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};