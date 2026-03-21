class Solution {
public:
    int dp[1001][2001];
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,0xc0,sizeof(dp));
        dp[0][0]=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            memcpy(dp[i+1],dp[i],sizeof(dp[0]));
            for(int j=0,s=0;j<piles[i].size();j++){
                s+=piles[i][j];
                for(int l=0;l+j+1<=k;l++){
                    dp[i+1][l+j+1]=max(dp[i+1][l+j+1],dp[i][l]+s);
                }
            }
        }
        return dp[n][k];
    }
};