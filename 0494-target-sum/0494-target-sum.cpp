class Solution {
public:
    int findTargetSumWays(vector<int>& a, int tar) {
        int n=a.size(); int tot=accumulate(a.begin(),a.end(),0);
        if(tot<abs(tar)||((tot+tar)&1) || ((tot+tar)<0))return 0;
        int star=(tot+tar)/2;
        vector<vector<int>>dp(n+1,vector<int>(star+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=star;j++){
                int exc=dp[i-1][j];
                int inc=0;
                if(a[i-1]<=j){
                    inc=dp[i-1][j-a[i-1]];
                }
                dp[i][j]=exc+inc;
            }
        }
        return dp[n][star];
    }
};