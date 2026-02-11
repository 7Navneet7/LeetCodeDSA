class Solution {
public:
    int atmostK(vector<int>&nums,int k){
        int n=nums.size();
        if(k<0)return 0;
        int l=0;map<int,int>mp;int ans=0;
        for(int r=0;r<n;r++){
            if(mp[nums[r]]==0)k--;
            mp[nums[r]]++;
            while(k<0 ){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)k++;
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums,k)-atmostK(nums,k-1);
    }
};