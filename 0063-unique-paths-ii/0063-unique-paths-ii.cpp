class Solution {
public:
    int util(vector<vector<int>>grid,vector<vector<int>>&dp,int i,int j,int n,int m){
        if(i>n||j>m)return 0;
        if(grid[i][j]==1)return 0;
        if(i==n and j==m)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int r=util(grid,dp,i,j+1,n,m);
        int d=util(grid,dp,i+1,j,n,m);
        return dp[i][j]=r+d;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return util(grid,dp,0,0,n-1,m-1);
    }
};