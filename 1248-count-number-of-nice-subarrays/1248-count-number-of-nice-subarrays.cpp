class Solution {
public:
    int atmostK(vector<int>&nums,int k){
        int ans=0;map<int,int>mp;
        int n=nums.size();
        int l=0;
        for(int r=0;r<n;r++){
            if((nums[r]&1))k--;
            mp[nums[r]]++;
            while(k<0){
                mp[nums[l]]--;
                if((nums[l]&1))k++;
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostK(nums,k)-atmostK(nums,k-1);
    }
};