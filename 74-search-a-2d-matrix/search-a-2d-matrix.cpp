class Solution {
public:
    int lowerBound(vector<int>&v,int n,int x){
        int l=0,h=n-1,ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(v[m]>=x){h=m-1;ans=m;}
            else l=m+1;
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m=mat.size();int n=mat[0].size();int ans;
        for(int i=0;i<m;i++){
            ans=lowerBound(mat[i],n,tar);
            if(ans!=-1 && mat[i][ans]==tar)return true;
        }
        return false;
    }
};