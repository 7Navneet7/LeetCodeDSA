class Solution {
public:

    void findComb(int ind,int target,vector<int>&nums,vector<vector<int>>&combinations,vector<int>&sequence){
        int n=nums.size();
        if(ind==n){
            return;
        }
        if(target==0){
            combinations.push_back(sequence);
            return;
        }
        if(nums[ind]>target){
            return;
        }
        if(nums[ind]<=target){
            sequence.push_back(nums[ind]);
            findComb(ind,target-nums[ind],nums,combinations,sequence);
            sequence.pop_back();
            findComb(ind+1,target,nums,combinations,sequence);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds; vector<vector<int>>ans;
        findComb(0,target,candidates,ans,ds);
        return ans;
    }
};