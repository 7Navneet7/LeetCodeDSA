class Solution {
public:
    int minimumTotal(vector<vector<int>>& mat) {
        int r=mat.size();int c=mat[r-1].size();
        for(int i=1;i<r;i++){
            for(int j=0;j<mat[i].size();j++){
                int top=(j<mat[i-1].size())?mat[i-1][j]:INT_MAX;
                int tl=(j>0)?mat[i-1][j-1]:INT_MAX;
                mat[i][j]=mat[i][j]+min(top,tl);
            }
        }
        int mx=INT_MAX;
        for(int j=0;j<c;j++){
            mx=min(mx,mat[r-1][j]);
        }
        return mx;
    }
};