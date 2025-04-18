class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxProd=1,mnProd=1,ans=INT_MIN;
        for(int x:nums){
            int a=mxProd*x;
            int b=mnProd*x;
            mxProd=max({x,a,b});
            mnProd=min({x,a,b});
            ans=max(ans,mxProd);
        }
        return ans;
    }
};