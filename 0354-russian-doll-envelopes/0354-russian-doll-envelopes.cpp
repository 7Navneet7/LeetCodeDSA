class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& ens) {
        sort(ens.begin(),ens.end(),[&](auto &a,auto &b){
            //descending heights for equal widths
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        //patience bianary search for lis
        //extract heights
        vector<int>tails;
        for(auto &x:ens){
            int h=x[1];
            auto it=lower_bound(tails.begin(),tails.end(),h);
            if(it==tails.end())tails.push_back(h);
            else{
                *it=h;
            }
        }
        return tails.size();

    }
};