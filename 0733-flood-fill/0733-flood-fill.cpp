class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int col) {
        int ro=mat.size(),co=mat[0].size();
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        int initcol=mat[sr][sc];
               if(col==initcol)return mat;
        q.push({sr,sc});
        mat[sr][sc]=col;
        while(!q.empty()){
            //int sz=q.size();
            //for(int i=0;i<sz;i++){
                auto[r,c]=q.front();
                q.pop();
                
                //mat[r][c]=col;
                for(auto[x,y]:dir){
                    int nr=r+x;int nc=c+y;
                    if(nr>=0 && nr<ro && nc>=0 && nc<co && mat[nr][nc]==initcol){
                        q.push({nr,nc});
                        mat[nr][nc]=col;

                    }
                }
            //}

        }
        return mat;
    }
};