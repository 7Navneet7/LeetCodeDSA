class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        // for fast look ups O(1)
        unordered_set<string>st(wd.begin(),wd.end());
        int n=s.size();
        //dp[i] tells if i can segement the substring s(0,...,i-1) into wd words
        vector<bool>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            //iterating on the possible split points to find the segmened parts
            // in word dict
            for(int j=0;j<i;j++){
                if(dp[j] && st.count(s.substr(j,i-j))){
                    dp[i]=1;
                    break;
                }
            }
        }

        return dp[n];
    }
};