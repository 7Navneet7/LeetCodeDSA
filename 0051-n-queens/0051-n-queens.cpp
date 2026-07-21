class Solution {
public:
    void backT(int r,int n,vector<string>&brd,vector<bool>&cols,
    vector<bool>&md,vector<bool>&ad,vector<vector<string>>&ans){
        //base case when all the rows have a queen
        if(r==n){
            ans.push_back(brd);return;
        }
        //trying to place the queen for the current row by trying diff cols
        for(int c=0;c<n;c++){
            int m1=(r-c)+(n-1);
            int a1=(r+c);
            // pruning to skip the cols and diags already under attack
            if(cols[c]||md[m1]||ad[a1])continue;
            brd[r][c]='Q';
            cols[c]=md[m1]=ad[a1]=1;
            //recurse for next queens placement
            backT(r+1,n,brd,cols,md,ad,ans);
            brd[r][c]='.';
            cols[c]=md[m1]=ad[a1]=0;

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>brd(n,string(n,'.'));
        //look up cheks for queen placement validity
        vector<bool>cols(n,0);
        //main diagonal check
        vector<bool>md(2*n-1,0);
        //anti diagonal check
        vector<bool>ad(2*n-1,0);
        //helper
        backT(0,n,brd,cols,md,ad,ans);
        return ans;
    }
};