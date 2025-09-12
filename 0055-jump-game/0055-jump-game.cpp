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
    bool canJump(vector<int>& nums) {
        return util(0,nums);
    }
};