using ll=long long;
class Solution {
public:
    long long minimumCost(string s, string t, int fc, int sc, int cc) {
        ll n=s.size();
        ll c01=0;
        ll c10=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='0' && t[i]=='1')c01++;
            else if(s[i]=='1' && t[i]=='0')c10++;
        }
        ll cost=0;
        if(2*fc>sc){
            ll mn=min(c01,c10);
            cost+=(mn)*sc;
            c10-=mn;c01-=mn;
        }
        else{
            ll mn=min(c01,c10);
            cost+=(mn*fc*2);
            c10-=mn;c01-=mn;
        }
        if(sc+cc<2*fc){
            ll mx=max(c10,c01);
            cost+=(mx/2)*(sc+cc);
            if(mx&1)cost+=fc;
        }
        else{
            ll mx=max(c10,c01);
            cost+=mx*fc;
        }
        return cost;      
    }
};