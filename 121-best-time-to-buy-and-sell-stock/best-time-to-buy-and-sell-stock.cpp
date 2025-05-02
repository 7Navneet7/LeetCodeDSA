class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int res=0;int ind1=-1;
    //     auto min_it=min_element(prices.begin(),prices.end());
    //     if(min_it==prices.end()-1){
    //         min_it=min_element(prices.begin(),prices.end()-1);
    //     }
    //     ind1=distance(prices.begin(),min_it);
    //     int mx=*max_element(min_it,prices.end());
    //     if(mx-prices[ind1]>0)return mx-prices[ind1];
    //     else return 0;
        
    // }

    int maxProfit(vector<int>& prices){
        int n=prices.size();
        //int res=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         //if(prices[j]-prices[i]>0){
        //             res=max(res,prices[j]-prices[i]);
        //         //}
        //     }
        // }
        //return res;

        int minPrice=INT_MAX,maxPro=0;
        for(int i=0;i<n;i++){
            if(prices[i]<minPrice)minPrice=prices[i];
            int pro=prices[i]-minPrice;
            if(pro>maxPro)maxPro=pro;
        }
        return maxPro;
    }
};