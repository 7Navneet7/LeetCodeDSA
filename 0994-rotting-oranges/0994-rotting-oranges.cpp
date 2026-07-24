class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rs=grid.size(),cs=grid[0].size();
        //init the state
        queue<pair<int,int>>q;int fc=0;
        for(int i=0;i<rs;i++){
            for(int j=0;j<cs;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fc++;
            }
        }
        int tm=0;
        while(!q.empty() && fc>0){
            tm++;
            int sz=q.size();
            while(sz--){
            auto cr=q.front();
            q.pop();
            int x=cr.first;int y=cr.second;
            if(x-1>=0 && grid[x-1][y]==1){
                fc--;
                grid[x-1][y]=2;
                q.push({x-1,y});
            }
            if(y-1>-1 && grid[x][y-1]==1){
                fc--;
                grid[x][y-1]=2;
                q.push({x,y-1});
            }
            if(x+1<rs && grid[x+1][y]==1){
                fc--;q.push({x+1,y});
                grid[x+1][y]=2;
            }
            if(y+1<cs && grid[x][y+1]==1){
                fc--;q.push({x,y+1});
                grid[x][y+1]=2;
            }
            }

        }
        
        if(fc==0)return tm;
        return -1;
    }
};