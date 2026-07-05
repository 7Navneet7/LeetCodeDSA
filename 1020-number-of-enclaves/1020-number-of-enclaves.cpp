class Solution {
public:
    void dfs(int r,int c,int ro,int co,vector<vector<int>>&mat){
        if(r<0||r>ro-1||c<0||c>co-1||mat[r][c]!=1)return;
        mat[r][c]=2;
        dfs(r-1,c,ro,co,mat);
        dfs(r+1,c,ro,co,mat);
        dfs(r,c-1,ro,co,mat);
        dfs(r,c+1,ro,co,mat);
        
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int ro=mat.size();int co=mat[0].size();
        for(int i=0;i<ro;i++){
            if(mat[i][co-1]==1)dfs(i,co-1,ro,co,mat);
            if(mat[i][0]==1)dfs(i,0,ro,co,mat);
        }
        for(int i=0;i<co;i++){
            if(mat[0][i]==1)dfs(0,i,ro,co,mat);
            if(mat[ro-1][i]==1)dfs(ro-1,i,ro,co,mat);
        }
        int c=0;
        for(int i=0;i<ro;i++){
            for(int j=0;j<co;j++){
                if(mat[i][j]==1)c++;
            }
        }
        return c;

    }
};