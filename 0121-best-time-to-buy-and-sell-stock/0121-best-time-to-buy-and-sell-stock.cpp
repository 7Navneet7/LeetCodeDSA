class Solution {
public:
    int maxProfit(vector<int>& pri) {
        int n=pri.size();
        //int mx=pri[0];int mn=pri[0];
        
        // for(int i=0;i<n;i++){
        //     mx=max(mx,pri[i]);
        //     mn=min(mn,pri[i]);

        // }
        // int mx=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         mx=max(pri[j]-pri[i],mx);
        //     }
        // }
        // return mx;
        int mnp=pri[0];int mxp=0;
        for(int i=1;i<n;i++){
            mnp=min(mnp,pri[i]);
            mxp=max(mxp,pri[i]-mnp);
        }
        return mxp;
    }
};