using ll=long long;
class Solution {
public:
    int minimumK(vector<int>& nums) {
        ll n=nums.size();
        auto check=[&](ll k)->bool{
            ll tot=0;
            for(auto x:nums){
                tot+=(x+k-1)/k;
            }
            return tot<=(k*k);
        };
        ll l=1,h=1e9;
        while(l<h){
            ll m=(l+h)/2;
            if(check(m)){
                h=m;
            }
            else{
                l=m+1;
            }
        }
        return (int)l;
    }
};