using ll=long long;
class Solution {
public:
    int countDigitOne(int n) {
        ll fact=1,cnt=0;
        while(fact<=n){
            ll h=(n/(fact*10));
            ll c=(n/fact)%10;
            ll l=(n%fact);
            if(c==0)cnt+=(h*fact);
            else if(c==1)cnt+=(h*fact)+l+1;
            else cnt+=((h+1)*fact);
            fact*=10;
        }
        return cnt;
    }
};