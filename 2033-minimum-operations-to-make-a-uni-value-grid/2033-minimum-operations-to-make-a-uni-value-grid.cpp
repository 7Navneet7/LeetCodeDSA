class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>all;
        for(auto &row:grid){
            for(auto x1:row){
                all.push_back(x1);
            }
        }
        int mod=all[0]%x;
        for(int nu:all){
            if(nu%x!=mod)return -1;
        }
        sort(all.begin(),all.end());
        int med=all[all.size()/2];
        int ops=0;
        for(int nu:all){
            ops+=(abs(med-nu)/x);
        }
        return ops;
    }
};