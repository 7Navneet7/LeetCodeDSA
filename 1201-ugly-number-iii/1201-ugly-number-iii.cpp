using ll=long long;
class Solution {
public:
    ll lcmSafe(ll x,ll y,ll lim){
        if(x==0||y==0)return x+y;
        ll g=gcd(x,y);
        if(x>lim/(y/g))return lim+1;
        return (x/g)*y;
    }

    ll cntUgly(ll x,ll a,ll b,ll c){
        ll ab=lcmSafe(a,b,x);
        ll bc=lcmSafe(b,c,x);
        ll ac=lcmSafe(a,c,x);
        ll abc=lcmSafe(ab,c,x);
        ll cnt=x/a+x/b+x/c;
        cnt-=(x/ab+x/bc+x/ac);
        cnt+=(x/abc);
        return cnt;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ld=1;ll hd=2e18,ans=0;
        while(ld<=hd){
            ll md=(ld+hd)/2;
            if(cntUgly(md,a,b,c)>=n){
                ans=md;
                hd=md-1;
            }
            else ld=md+1;
        }
        return ans;
    }
};