typedef __int128_t ll;
class Solution {
public:
    //using ll=long long;
    bool solve(int i,ll prod,ll targ,vector<int>&nums){
        if(prod>targ)return false;
        if(prod==targ)return true;
        if(i==nums.size())return false;

        if(solve(i+1,prod*nums[i],targ,nums))return true;

        if(solve(i+1,prod,targ,nums))return true;
        return false;
    }
    bool checkEqualPartitions(vector<int>& nums, ll target) {
        int n=nums.size();
        ll tot=1;
        for(int x:nums){
            tot*=x;
            if((ll)tot > (ll)target*target)return false;
        }
        if(tot!= (ll)target*target)return false;
        return solve(0,1,target,nums);
    }
};