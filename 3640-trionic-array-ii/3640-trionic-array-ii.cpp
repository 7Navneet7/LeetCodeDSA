using ll=long long;
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        ll n=nums.size();ll inf=-1e17;
        ll a=inf,b=inf,c=inf;ll res=inf;
        ll prev=nums[0];
        for(ll i=1;i<n;i++){
            ll curr=nums[i];
            ll na=inf,nb=inf,nc=inf;
            if(curr>prev){
                na=max(a,prev)+curr;
                nc=max(b,c)+curr;
            }
            else if(curr<prev){
                nb=max(b,a)+curr;
            }
            a=na;b=nb;c=nc;
            res=max(res,c);prev=curr;
        }
        return res;
    }
};