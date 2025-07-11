class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        if(mat==target)return true;
        int deg=3;
        while(deg--){
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n/2;j++){
                    swap(mat[i][j],mat[i][n-1-j]);
                }
            }
            if(mat==target)return true;
        }
        return false;
    }
};