class Solution {
public:
    // int util(vector<int>&nums,int remTarg,int k,vector<int>&dp){
    //     if(remTarg==0)return 1;
    //     if(remTarg<0)return 0;
    //     if(dp[remTarg]!=-1)return dp[remTarg];

    // }
    int mod=1e9+7;
    int func(int n,int num,int k,vector<vector<int>>&dp){
        if(n==0)return 1;
        if(n<0)return 0;
        if(pow(num,k)>n)return 0;
        if(dp[n][num]!=-1)return dp[n][num];
        int temp=pow(num,k);
        int pick=func(n-temp,num+1,k,dp);
        int skip=func(n,num+1,k,dp);
        return dp[n][num]=(skip % mod + pick % mod)% mod;
    }
    int numberOfWays(int n, int x) {
        int maxBase=1;int p=pow(maxBase,x);
        while(pow(maxBase,x)<n){
            ++maxBase;
        }
        vector<vector<int>>dp(n+1,vector<int>(maxBase+1,-1));
        return func(n,1,x,dp);
    }
};