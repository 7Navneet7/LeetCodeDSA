class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sl=s.size();
        vector<vector<int>>dp(sl,vector<int>(sl,0));
        //single char is always pal
        for(int i=0;i<sl;i++){
            dp[i][i]=1;
        }
        for(int i=sl-1;i>=0;i--){
            for(int j=i+1;j<sl;j++){
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][sl-1];

    }
};