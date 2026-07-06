class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        if(mat[0][0]==1||mat[n-1][n-1]==1)return -1;
        if(n==1)return 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dist(n,vector<int>(n,0));
        dist[0][0]=1;
        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto[r,c]=q.front();q.pop();
            if(r==n-1 && c==n-1)return dist[r][c];
            for(int i=0;i<8;i++){
                int nr=r+dx[i];int nc=c+dy[i];
                if(nr>=0&&nr<n && nc>=0 && nc<n && mat[nr][nc]==0 && dist[nr][nc]==0){
                    dist[nr][nc]=1+dist[r][c];
                    q.push({nr,nc});
                }
            }

        }
        return -1;
    }
};