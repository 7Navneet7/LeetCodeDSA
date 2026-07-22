class Solution {
public:
    void backT(int r,int n,vector<string>&brd,vector<bool>&cols,vector<bool>&mainD,
    vector<bool>&antiD,vector<vector<string>>&ans){
        //filled all the rows
        if(r==n){
            ans.push_back(brd);return;
        }
        //trying columns
        for(int c=0;c<n;c++){
            int md=((r-c)+(n-1));
            int ad=r+c;
            bool f=cols[c]||mainD[md]||antiD[ad];
            if(f)continue;
            brd[r][c]='Q';
            cols[c]=mainD[md]=antiD[ad]=1;
            //recurse for further rows
            backT(r+1,n,brd,cols,mainD,antiD,ans);
            brd[r][c]='.';
            cols[c]=mainD[md]=antiD[ad]=0;

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>brd(n,string(n,'.'));
        vector<vector<string>>ans;
        vector<bool>col(n,0);
        vector<bool>mainD(2*n-1,0);
        vector<bool>antiD(2*n-1,0);
        backT(0,n,brd,col,mainD,antiD,ans);
        return ans;
    }
};