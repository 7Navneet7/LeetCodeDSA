class Solution {
public:

    void uniqueSubsets(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
        int n=nums.size();
        
        // if(ind==n){
            
        //     return;
        // }
        ans.push_back(ds);    
        //ds.pop_back();
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            //ans.push_back(ds);
            uniqueSubsets(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        uniqueSubsets(0,nums,ans,ds);
        return ans;
    }
};