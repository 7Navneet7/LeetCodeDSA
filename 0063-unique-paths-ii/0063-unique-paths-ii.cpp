class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int r=mat.size();int c=mat[0].size();
        if(mat[0][0]==1 && mat[r-1][c-1]==1)return 0;
        vector<int>dp(c,0);
        dp[0]=1;
        // let's iterate over  the roes
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    dp[j]=0;
                }
                else if(j>0){
                    dp[j]=dp[j-1]+dp[j];
                }
            }
        }
        return dp[c-1];
    }
};