class Solution {
public:
    int coinChange(vector<int>& co, int amt) {
        int n=co.size();
        vector<int>dp(amt+1,amt+1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=co[i];j<=amt;j++){
                dp[j]=min(dp[j],1+dp[j-co[i]]);
            }
        }
        return (dp[amt]!=amt+1)?dp[amt]:-1;
    }
};