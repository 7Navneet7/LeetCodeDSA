class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int r=mat.size();int c=mat[0].size();
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                int top=mat[i-1][j];
                int tl=(j>0)?mat[i-1][j-1]:INT_MAX;
                int tr=(j<c-1)?mat[i-1][j+1]:INT_MAX;
                mat[i][j]=mat[i][j]+min({top,tl,tr});
            }
        }
         int mn=mat[r-1][c-1];
         for(int j=0;j<c-1;j++){
            mn=min(mn,mat[r-1][j]);
         }
         return mn;
    }
};