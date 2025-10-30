using ll=long long;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>v(n);
        for(auto &x:nums){
            if(x<0)x=abs(x);
        }
        sort(nums.begin(),nums.end(),greater<int>());ll j=0;
        for(ll i=0;i<n;i+=2){
            v[i]=nums[j];j++;
        }
        for(ll i=1;i<n;i+=2){
            v[i]=nums[j];j++;
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(i&1)ans-=pow(v[i],2);
            else ans+=pow(v[i],2);
        }
        return ans;
    }
};