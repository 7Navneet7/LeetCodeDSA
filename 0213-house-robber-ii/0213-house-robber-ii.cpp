class Solution {
public:
    int roblin(vector<int>&a,int st,int en){
        int len=en-st+1;
        if(len==1)return a[st];
        vector<int>dp(len,0);
        dp[0]=a[st];
        dp[1]=max(a[st],a[st+1]);
        for(int i=2;i<len;i++){
            dp[i]=max(dp[i-2]+a[st+i],dp[i-1]);
        }
        return dp[len-1];
    }
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        if(n==2)return max(a[0],a[1]);
        int c1=roblin(a,0,n-2);
        int c2=roblin(a,1,n-1);
        return max(c1,c2);
    }
};