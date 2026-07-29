class Solution {
public:
    int maxProfit(vector<int>& pri) {
        int n=pri.size();
        //can have max 2 transactions so having 4 financial states for each price
        int b1=INT_MIN,b2=INT_MIN;
        int s1=0,s2=0;
        for(int pr:pri){
            // max profits after
            b1=max(b1,-pr);
            s1=max(s1,pr+b1);
            b2=max(b2,s1-pr);
            s2=max(s2,b2+pr);
        }
        return s2;
        
    }
};