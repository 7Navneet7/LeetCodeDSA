using ll=long long;
class Solution {
public:
    // long long maxProduct(vector<int>& nums) {
    //     ll n=nums.size();
    //     if(n==3){
    //         if(count(nums.begin(),nums.end(),0)>1)return 0;
    //     }
    //     ll mx1=-1e6,mx2=-1e6;
    //     for(ll i=0;i<n;i++){
    //         if(llabs(nums[i])>mx1 && nums[i]!=0){
    //             if(mx1!=-1e6)mx2=llabs(mx1);
    //             mx1=llabs(nums[i]);
    //         }
    //         else if(llabs(nums[i])>mx2 && nums[i]!=0){
    //             mx2=llabs(nums[i]);
    //         }
    //     }
    //     //return mx1;
    //     return llabs(mx1*mx2*(1e5));
    // }


    long long maxProduct(vector<int>& nums){
        ll n=nums.size();
        for(ll i=0;i<n;i++){
            //nums[i]=llabs(nums[i]);
            if(nums[i]<0)nums[i]=nums[i]*-1;
        }
        sort(nums.begin(),nums.end());
        ll mx1=nums[n-1];ll mx2=nums[n-1];
        ll ans=1;
        ans*=(1ll*nums[n-1]);
        ans*=(1ll*nums[n-2]);
        ans*=(1ll*100000);
        return abs(ans);    
        //return abs(1ll*mx1*mx2*1e5);
    }
};