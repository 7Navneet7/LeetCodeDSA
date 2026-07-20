class Solution {
    using ll=long long;
    ll md=1e9+7;
public:
    ll power(ll bs,ll ex){
        if(ex==0)return 1;
        if(ex==1)return bs;
        if(ex%2==0){
            return power((bs*bs)%md,ex/2)%md;
        }
        return bs*power(bs,ex-1)%md;
    }
    int countGoodNumbers(long long n) {
        ll evp=(n+1)/2;
        ll odp=n/2;
        int ans=(power(5,evp)%md)*(power(4,odp)%md)%md;
        return ans;
    }
};