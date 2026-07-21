class Solution {
public:
    //he;per fun
    bool dfs(int x,int y,int idx,vector<vector<char>>&brd,string &wd){
        //base case
        if(idx==wd.size()){
            //matched all the characters in brd
            return 1;
        }
        //out of bound checks
        int r=brd.size();int c=brd[0].size();
        if(x<0||y <0||x>=r||y>=c)return 0;
        //mismatch check
        if(brd[x][y]!=wd[idx])return 0;
        char tmp=brd[x][y];
        brd[x][y]='#';
        //explore all the 4 directions
        bool found=(dfs(x-1,y,idx+1,brd,wd)||
                    dfs(x+1,y,idx+1,brd,wd)||
                    dfs(x,y-1,idx+1,brd,wd)||
                    dfs(x,y+1,idx+1,brd,wd));
        brd[x][y]=tmp;
        return found;

        
    }
    bool exist(vector<vector<char>>& brd, string wd) {
        int r=brd.size();int c=brd[0].size();
        //grid scan to initate my dfs at wd[0]
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(brd[i][j]==wd[0]){
                    if(dfs(i,j,0,brd,wd))return 1;
                }
            }
        }
        return 0;
    }
};