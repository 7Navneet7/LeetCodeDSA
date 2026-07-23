class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int rs=mat.size();int cs=mat[0].size();
        int lc=0;int hc=cs-1;
        // while(lc<=hc){
        //     int mc=lc+(hc-lc)/2;
        //     if(tar>=)
        // } 
        int r=0;int c=cs-1;
        while(1){
            if(mat[r][c]==tar)return 1;
            else if(mat[r][c]<tar){
                if(r==rs-1)return 0;
                else r++;
            }
            else{
                if(c==0)return 0;
                else c--;
            }
        }
        return 0;
    }
};