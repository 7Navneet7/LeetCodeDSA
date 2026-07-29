class Solution {
public:
    int maxProfit(vector<int>& pri) {
        // basce cases
        int n=pri.size();
        vector<int>hold(n),sold(n),rest(n);
        hold[0]=-pri[0];
        sold[0]=INT_MIN;
        rest[0]=0;
        for(int i=1;i<pri.size();i++){
            // either holding a prev stock or bought today's stock from yesterday's 
            // rest day profit
            hold[i]=max(hold[i-1],rest[i-1]-pri[i]);
            //sold the yesterday's hold stock
            sold[i]=hold[i-1]+pri[i];
            //no buying like yesterday or yesterday was a sold day so today rest
            rest[i]=max(rest[i-1],sold[i-1]);
        }
        //if the last day is also a sold day, max profit is sold[n-1]
        //else rest[n-1] will cover up
        return max(sold[ n-1],rest[n-1]);
    }
};