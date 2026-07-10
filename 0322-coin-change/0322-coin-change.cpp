class Solution {
public:
    int coinChange(vector<int>& a, int t) {
        int n=a.size();
        vector<int>dp(t+1,t+1);
        dp[0]=0;
        for(int i=1;i<=t;i++){
            for(int j=0;j<n;j++){
                if(a[j]<=i){
                    dp[i]=min(dp[i],1+dp[i-a[j]]);
                }
            }
        }
        return dp[t]!=t+1?dp[t]:-1;
    }
};