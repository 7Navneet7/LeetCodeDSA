class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int row=m-k+1,col=n-k+1;
        vector<vector<int>>ans(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                vector<int>val(k*k);
                int ind=0;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        val[ind++]=grid[x][y];
                    }
                }
                sort(val.begin(),val.end());
                val.erase(unique(val.begin(),val.end()),val.end());
                if(val.size()<=1){ans[i][j]=0;continue;}
                int mini=INT_MAX;
                for(int t=1;t<val.size();t++){
                    int dif=val[t]-val[t-1];
                    if(dif<mini)mini=dif;
                }
                ans[i][j]=mini;
            }
        }
        return ans;
    }
};