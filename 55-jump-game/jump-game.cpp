class Solution {
public:
    bool util(int ind,vector<int>&nums){
        int n=nums.size();
        if(ind==n-1)return true;
        if(nums[ind]==0)return false;
        int rang=ind+nums[ind];
        for(int i=ind+1;i<=rang;i++){
            if(i<n && util(i,nums))return true;
        }
        return false;
    }
    bool util1(int ind,vector<int>&nums,vector<int>&dp){
        if(dp[ind]!=-1)return dp[ind];
        if(ind==nums.size()-1)return dp[ind]=true;
        if(dp[ind]==0)return dp[ind]=false;
        int rang=ind+nums[ind];
        for(int i=ind+1;i<=rang;i++){
            if(i<nums.size()&&util1(i,nums,dp))return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return util1(0,nums,dp);
    }
};