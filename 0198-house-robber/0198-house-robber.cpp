class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        vector<int>dp(n,0);
        dp[0]=a[0];
        if(n==0)return 0;
        if(n==1)return a[0];
        for(int i=1;i<n;i++){
            int ch1=(i>=2)?dp[i-2]+a[i]:a[i];
            int ch2=dp[i-1];
            dp[i]=max(ch1,ch2);
        }
        return dp[n-1];
    }
};