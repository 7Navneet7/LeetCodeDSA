class Solution {
    
public:
    //1e9 scales down to 4*1e7
    double dp[200][200];
    bool vis[200][200];
    double util(int a,int b){
        //both got empty simultaneously
        if(a<=0 && b<=0)return 0.5;
        if(a<=0)return 1.0;
        if(b<=0)return 0.0;
        if(vis[a][b])return dp[a][b];
        double o1=util(a-4,b);
        double o2=util(a-3,b-1);
        double o3=util(a-2,b-2);
        double o4=util(a-1,b-3);
        dp[a][b]=0.25*(o1+o2+o3+o4);
        vis[a][b]=1;
        return dp[a][b];
    }
    double soupServings(int n) {
        //converting these volumes to units (compressed)
        //unit size of 25 
        if(n>=4800)return 1.0;
        int s_n=(n+24)/25;
        for(int i=0;i<200;i++){
            for(int j=0;j<200;j++)vis[i][j]=0;
        }
        double res=util(s_n,s_n);
        return res;

    }
};