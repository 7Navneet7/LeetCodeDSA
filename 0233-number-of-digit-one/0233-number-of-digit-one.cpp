using ll=long long;
class Solution {
public:
    int dp[12][2];bool vis[12][2];
    string s;
    int dfs(int pos,bool t){
        if(pos==s.size())return 0;
        if(vis[pos][t])return dp[pos][t];
        vis[pos][t]=1;
        int ans=0;
        int lim=t?s[pos]-'0':9;
        for(int dig=0;dig<=lim;dig++){
            bool nt= t&&(dig==lim);ll add=0;
            
            if(dig==1){
                ll rem=s.size()-pos-1;ll reman=1;
                if(!nt){
                for(int j=0;j<rem;j++)reman*=10;
                }
                else{
                    reman=stoll(s.substr(pos+1))+1;
                }
                add=reman;

            }
            ans+=add+dfs(pos+1,nt);
        }
        return ans;
    }
    int countDigitOne(int n) {
        s=to_string(n);
        memset(vis,0,sizeof(vis));
        return dfs(0,true);
    }
};