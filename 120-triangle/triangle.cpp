class Solution {
public:
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int row = triangle.size();
    //     vector<int> memo = triangle[row-1];

    //     for (int r = row-2; r >= 0; r--) {
    //         for (int c = 0; c <= r; c++) {
    //             memo[c] = min(memo[c], memo[c+1]) + triangle[r][c];
    //         }
    //     }

    //     return memo[0];        
    // }





    int minPath(int i,int j,vector<vector<int>>&tri,int n,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==n-1)return tri[n-1][j];
        int down=tri[i][j]+minPath(i+1,j,tri,n,dp);
        int diag=tri[i][j]+minPath(i+1,j+1,tri,n,dp);
        return dp[i][j]=min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& tri){
        int n=tri.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return minPath(0,0,tri,n,dp);
        
    }
};