using ll=long long;
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        ll sum=accumulate(cost.begin(),cost.end(),0ll);
        map<char,ll>mp;
        for(ll i=0;i<s.size();i++){
            mp[s[i]]+=cost[i];
        }
        ll mn=LONG_MAX;
        for(auto&[k,v]:mp){
            ll co=sum-v;
            mn=min(co,mn);
        }
        return mn;
    }
};