class Solution {
public:
    int maxProfit(vector<int>& pri, int fee) {
        // int pr=0;
        // for(int i=1;i<pri.size();i++){
        //     if(pri[i]>pri[i-1]+fee){
        //         pr+=(pri[i]-pri[i-1])-fee;
        //     }
        // }
        // return pr;
        //2 states (hold and cash) for all indices
        int n=pri.size();
        vector<int>hold(n),cash(n);
        hold[0]=-pri[0];
        cash[0]=0;
        for(int i=1;i<n;i++){
            hold[i]=max(hold[i-1],cash[i-1]-pri[i]);
            cash[i]=max(cash[i-1],hold[i-1]+pri[i]-fee);
        }
        return cash[n-1];
    }
};