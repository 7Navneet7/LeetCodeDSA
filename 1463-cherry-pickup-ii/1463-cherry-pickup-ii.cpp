class Solution {
public:
    int ro,co;
    int dp[71][71][71];
    int dfs(vector<vector<int>>&mat,int r,int c1,int c2){
        if(r==ro)return 0;
        if(c1<0||c2<0||c1>=co||c2>=co)return INT_MIN;
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        int cher=0;
        if(c1==c2)cher=mat[r][c1];
        else cher=mat[r][c1]+mat[r][c2];
        //now processing all 9 down movement combos
        int mx=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                mx=max(mx,dfs(mat,r+1,c1+i,c2+j));
            }
        }
        return dp[r][c1][c2]=mx+cher;

    }
    int cherryPickup(vector<vector<int>>& mat) {
        ro=mat.size();co=mat[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(mat,0,0,co-1);
    }
};