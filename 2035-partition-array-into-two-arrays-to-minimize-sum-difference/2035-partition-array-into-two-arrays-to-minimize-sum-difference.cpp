class Solution {
public:
    vector<vector<int>>getSizesAndSums(vector<int>&sub){
        int n=sub.size();
        vector<vector<int>>sts(n+1);
        int tsb=(1<<n);
        for(int ma=0;ma<tsb;ma++){
            int cs=0;
            int ep=0;
            for(int i=0;i<n;i++){
                if((ma & (1<<i))!=0){
                    cs+=sub[i];
                    ep++;
                }
            }
            sts[ep].push_back(cs);
        }
        return sts;
    }
    int minimumDifference(vector<int>& a) {
        int tl=a.size();
        int n=tl/2;
        int ts=accumulate(a.begin(),a.end(),0);
        int tas=ts/2;

        vector<int>lh(a.begin(),a.begin()+n);
        vector<int>rh(a.begin()+n,a.end());
        vector<vector<int>>lg=getSizesAndSums(lh);
        vector<vector<int>>rg=getSizesAndSums(rh);
        for(int i=0;i<=n;i++){
            sort(rg[i].begin(),rg[i].end());
        }
        int md=INT_MAX;
        for(int k=0;k<=n;k++){
            int rrs=n-k;
            for(int ls:lg[k]){
                int irs=tas-ls;
                auto& rcs=rg[rrs];
                auto it=lower_bound(rcs.begin(),rcs.end(),irs);
                if(it!=rcs.end()){
                    int csu=ls+*it;
                    md=min(md,abs(ts-2*csu));

                }
            }
        }
        return md;
    }
};