using ll =long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll n=grid.size(),m=grid[0].size();
        ll tot=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                tot+=grid[i][j];
            }
        }
        if(tot & 1)return false;
        ll rowsum=0,colsum=0;
        for(ll i=0;i<n-1;i++){
            for(ll j=0;j<m;j++){
                rowsum+=grid[i][j];
            }
            if(rowsum*2==tot)return true;
        }
        vector<ll>colsums(m-1);
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m-1;j++){
                colsums[j]+=grid[i][j];
            }
        }
        
        for(ll i=0;i<m-1;i++){
            colsum+=colsums[i];
            if(colsum*2==tot)return true;
        }
        return false;
    }
};