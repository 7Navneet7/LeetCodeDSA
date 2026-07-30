class Solution {
public:
    int lengthOfLIS(vector<int>& nu) {
        int n=nu.size();
        vector<int>dp(n,1);
        int mxl=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nu[i]>nu[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            mxl=max(mxl,dp[i]);
        }
        return mxl;
    }
};