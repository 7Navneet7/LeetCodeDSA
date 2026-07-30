class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nu) {
        sort(nu.begin(),nu.end());
        int n=nu.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int mxl=1;
        int mxi=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nu[i]%nu[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(mxl<dp[i]){
                mxl=dp[i];mxi=i;
            }
        }
        int curr=mxi;
        vector<int>res;
        while(curr!=-1){
            res.push_back(nu[curr]);
            curr=prev[curr];
        }
        return res;
    }
};