class Solution {
public:
    bool binSearch(vector<int>&v,int m,int x){
        int l=0,h=m-1;
        while(l<=h){
            int md=(l+h)/2;
            if(v[md]==x)return true;
            else if(v[md]>x)h=md-1;
            else l=md+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        for(int i=0;i<mat.size();i++){
            if(binSearch(mat[i],mat[0].size(),tar))return true;
        }
        return false;
    }
};