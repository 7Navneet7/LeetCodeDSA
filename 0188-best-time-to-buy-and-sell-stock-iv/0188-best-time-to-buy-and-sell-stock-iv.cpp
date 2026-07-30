class Solution {
public:
    int maxProfit(int k, vector<int>& pri) {
        int n=pri.size();
        if(k>=n/2){
            //no constraint so infinite transactions
            int pr=0;
            for(int i=1;i<pri.size();i++){
                if(pri[i]>pri[i-1]){
                    pr+=pri[i]-pri[i-1];
                }
            }
            return pr;
        }
        //we will have 2 states (buy and sell) for each of the k transactions
        // buy and sell denote the max profit possible at that transacn
        vector<int>buy(k,INT_MIN);
        vector<int>sell(k,0);
        for(int pr:pri){
            buy[0]=max(buy[0],-pr);
            sell[0]=max(sell[0],buy[0]+pr);
            for(int j=1;j<k;j++){
                buy[j]=max(buy[j],sell[j-1]-pr);
                sell[j]=max(sell[j],buy[j]+pr);
            }
        }
        return sell[k-1];
    }
};