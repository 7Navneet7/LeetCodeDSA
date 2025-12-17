using ll=long long;
class Solution {
public:
    long long minMoves(vector<int>& bal) {
        ll j=-1;ll n=bal.size();ll tot=0;
        for(ll i=0;i<n;i++){
            if(bal[i]<0)j=i;
            tot+=bal[i];
        }
        if(j==-1)return 0;ll ans=0;
        if(tot<0)return -1;
        for(ll d=1;bal[j]<0;d++){
            ll sto=bal[(j+d)%n]+bal[(j-d+n)%n];
            ans+=fmin(-bal[j],sto)*d;
            bal[j]+=sto;
        }
        return ans;
    }
};