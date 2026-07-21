class Solution {
public:
    using ll=long long;
    ll md=1e9+7;
    ll power(ll b,ll e){
        ll r=1;
        b=b%md;
        while(e>0){
            if(e&1){
                r=(r*b)%md;
            }
            b=(b*b)%md;
            e/=2;
        }
        return r;
    }
    int countGoodNumbers(long long n) {
        ll epos=(n+1)/2;
        ll opos=n/2;
        ll echoi=power(5,epos);
        ll ochoi=power(4,opos);
        return (echoi*ochoi)%md;
    }
};