using ll=long long;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        ll cnt=0;ll n=mat.size(),m=mat[0].size();ll su=0;ll mn=INT_MAX;
        bool z=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(mat[i][j]<0){
                    cnt++;
                    
                    
                }
                mn=fmin(mn,abs(mat[i][j]));
                su+=abs(mat[i][j]);
                if(mat[i][j]==0)z=1;
            }
        }
        if(cnt&1 && !z)return (su-2*mn);
        //else if(cnt&1 && f)return ()
        else return su;
    }
};