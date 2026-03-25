using ll=long long;
class Solution {
public:
    void gen(int st,int en,vector<int>nu,vector<ll>&r){
        int l=en-st;
        for(int mask=0;mask<(1<<l);mask++){
            ll su=0;
            for(int i=0;i<l;i++){
                if(mask &(1<<i)){
                    su+=nu[i+st];
                }
            }
            r.push_back(su);
        }
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<ll>left,right;
        gen(0,n/2,nums,left);
        gen(n/2,n,nums,right);
        sort(right.begin(),right.end());
        ll ans=LLONG_MAX;
        for(ll x:left){
            ll tar=goal-x;
            auto it=lower_bound(right.begin(),right.end(),tar);
            if(it!=right.end()){
                ans=fmin(ans,abs(*it+x-goal));
            }
            if(it!=right.begin()){
                it--;
                ans=fmin(ans,abs(*it+x-goal));
            }
        }
        return ans;
    }
};