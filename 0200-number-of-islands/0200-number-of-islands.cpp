class Solution {
public:
void dfs(int i,int j,int n,int m,vector<vector<char>>&mat){
    if(i<0||j<0||i>=n||j>=m||mat[i][j]!='1')return;
    mat[i][j]='0';
    dfs(i-1,j,n,m,mat);

    dfs(i+1,j,n,m,mat);

    dfs(i,j-1,n,m,mat);

    dfs(i,j+1,n,m,mat);
}
    int numIslands(vector<vector<char>>& mat) {
        int n=mat.size();int m=mat[0].size();
        int isl=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){
                    isl++;
                    dfs(i,j,n,m,mat);
                }
            }
        }
        return isl;
    }
};