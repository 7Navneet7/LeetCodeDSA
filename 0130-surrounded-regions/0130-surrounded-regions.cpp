class Solution {
public:
    void dfs(int r,int c,int ro,int co,vector<vector<char>>&mat){
        if(r<0||r>ro-1||c<0||c>=co||mat[r][c]!='O'){return;}
        mat[r][c]='#';
        dfs(r-1,c,ro,co,mat);
        dfs(r+1,c,ro,co,mat);
        dfs(r,c-1,ro,co,mat);
        dfs(r,c+1,ro,co,mat);
    }
    void solve(vector<vector<char>>& mat) {
        if(mat.empty())return;
        int ro=mat.size();int co=mat[0].size();
        //traverse left and right boundaries
        for(int r=0;r<ro;r++){
            if(mat[r][0]=='O')dfs(r,0,ro,co,mat);
            if(mat[r][co-1]=='O')dfs(r,co-1,ro,co,mat);
        }
        // top and bot boundaries
        for(int c=0;c<co;c++){
            if(mat[0][c]=='O')dfs(0,c,ro,co,mat);
            if(mat[ro-1][c]=='O')dfs(ro-1,c,ro,co,mat);
        }
        for(int i=0;i<ro;i++){
            for(int j=0;j<co;j++){
                if(mat[i][j]=='O')mat[i][j]='X';
                else if(mat[i][j]=='#')mat[i][j]='O';
            }
        }

    }
};