class Solution {
public:
    // vector<vector<int>> specialGrid(int N) {
    //     int v=(1<<(2*N))-1;int v1=v;
    //     vector<vector<int>>grid(2*N,vector<int>(2*N));
    //     int n=2*N;
    //     for(int i=0;i<n/2;i++){
    //         for(int j=0;j<n/2;j++){
    //             grid[i][j]=v;
    //             grid[i][n-1-i]=v1-v;
    //             v--;
    //         }
    //     }
    //     v=v-(1<<N);
    //     for(int i=n/2;i<n;i++){
    //         for(int j=0;j<n/2;j++){
    //             grid[i][j]=v;
    //             grid[i][n-1-i]=15-v;
    //             v--;
    //         }
    //     }
    //     return grid;
    // }


    vector<vector<int>> specialGrid(int N){
        int n=1<<N;
        vector<vector<int>>grid(n,vector<int>(n));
        solve(grid,0,n,0,n);
        return grid;
    }
    int val=0;
    void solve(vector<vector<int>>&grid,int rowstart,int rowend,int colstart,int colend){
        if(rowend-rowstart==1){
            grid[rowstart][colstart]=val++;return;
        }
        int midrow=(rowstart+rowend)/2;
        int midcol=(colstart+colend)/2;
        solve(grid,rowstart,midrow,midcol,colend);
        solve(grid,midrow,rowend,midcol,colend);
        solve(grid,midrow,rowend,colstart,midcol);
        solve(grid,rowstart,midrow,colstart,midcol);
    }
};