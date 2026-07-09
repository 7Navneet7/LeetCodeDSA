class Solution {
public:
    bool canPartition(vector<int>& a) {
        int tar=accumulate(a.begin(),a.end(),0);
        int n=a.size();
        if(tar&1)return 0;
        vector<vector<bool>>dp(n+1,vector<bool>((tar/2)+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int j=1;j<=tar/2;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=tar/2;j++){
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][(tar/2)];
    }
};