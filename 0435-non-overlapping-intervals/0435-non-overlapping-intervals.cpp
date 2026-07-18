class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& its) {
        int n=its.size();
        int mn=0;
        //1st get the least end points so that more future space generated
        sort(its.begin(),its.end(),[&](auto &a,auto &b){
            return a[1]<b[1];
        });
        int le=its[0][1];
        for(int i=1;i<n;i++){
            if(its[i][0]<le){
                mn++;

            }
            else le=its[i][1];
        }
        return mn;
    }
};