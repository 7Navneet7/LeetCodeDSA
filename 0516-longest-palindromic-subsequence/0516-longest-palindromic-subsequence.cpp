class Solution {
public:
    int lcs(string s,string t){
        int sl=s.size();int tl=t.size();
        vector<vector<int>>dp(sl+1,vector<int>(tl+1,0));
    
        for(int i=1;i<=sl;i++){
            for(int j=1;j<=tl;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[sl][tl];
    }
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        return lcs(s,r);
    }
};