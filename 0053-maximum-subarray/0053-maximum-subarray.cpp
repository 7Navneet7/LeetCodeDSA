class Solution {
public:
    int maxSubArray(vector<int>& nu) {
        int n=nu.size();
        vector<int>dp(n);
        dp[0]=nu[0];
        //dp[i] gives the max subarray sum ending at indx i
        //choose b/w global choice and local choice
        
        for(int i=1;i<n;i++){
            //extend or restart
            dp[i]=max(nu[i],dp[i-1]+nu[i]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};