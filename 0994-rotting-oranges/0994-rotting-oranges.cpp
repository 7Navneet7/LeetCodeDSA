class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();int cols=grid[0].size();
        int mins=0;int fres=0;
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fres++;
            }
        }
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        bool isrot=0;
        while(!q.empty()){
            int sz=q.size(); bool isrot=0;
            for(int i=0;i<sz;i++){
                auto[r,c]=q.front();q.pop();
                for(auto[dr,dc]:dir){
                    int nr=r+dr;int nc=c+dc;
                    if(nr>=0&&nr<rows && nc>=0 && nc<cols){
                        if(grid[nr][nc]==1){
                            grid[nr][nc]=2;fres--;
                            q.push({nr,nc});
                            isrot=1;
                        }
                    }
                }
            }
            if(isrot)mins++;
        }
        return (fres!=0?-1:mins);
    }
};