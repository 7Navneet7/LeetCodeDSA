class Solution {
public:
    int maxProfit(vector<int>& pri) {
        int n=pri.size();
        int pr=0;
        for(int i=1;i<n;i++){
            if(pri[i]>pri[i-1]){
                pr+=(pri[i]-pri[i-1]);
            }
        }
        return pr;
    }
};