class Solution {
public:
    // void solve(int ind,int targ,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
    //     if(ind==nums.size()){
    //         if(targ==0)ans.push_back(ds);
    //         return;
    //     }
    //     if(nums[ind]<=targ){
    //         ds.push_back(nums[ind]);
    //         solve(ind,targ-nums[ind],nums,ans,ds);
    //         ds.pop_back();
    //     }
    //     solve(ind+1,targ,nums,ans,ds);
    // }

    int util(vector<int>&nums,int remTarg,vector<int>&dp){
        if(remTarg==0)return 1;
        if(remTarg<0)return 0;
        if(dp[remTarg]!=-1)return dp[remTarg];

        int countComb=0;
        for(int i=0;i<nums.size();i++){
            countComb+=util(nums,remTarg-nums[i],dp);
        }
        return dp[remTarg]=countComb;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // vector<vector<int>>ans;
        // vector<int>ds;
        // solve(0,target,nums,ans,ds);
        // return ans.size();


        vector<int>dp(target+1,-1);
       // dp[0]=1;
        return util(nums,target,dp);
        
    }
};