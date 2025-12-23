class Solution {
public:
    // int find(int indr,int indc,vector<vector<int>>& grid,vector<vector<int>>&dp){
    //     int n=grid.size(); int m=grid[0].size(); int rmove=INT_MAX,bmove=INT_MAX;
    //     if(indr==0 && indc==0)return 0;
    //     if(indr>0){
    //         rmove=
    //     }
    // }

    int findUnique(int row,int col,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(row>=0 && col>=0 && obstacleGrid[row][col]==1)return 0;
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int left=findUnique(row,col-1,obstacleGrid,dp);
        int top=findUnique(row-1,col,obstacleGrid,dp);
        return dp[row][col]=left+top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=findUnique(n-1,m-1,obstacleGrid,dp);
        return ans;
        
    }
};