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


    void uniqueSubsets2(int ind,vector<int>&nums,set<vector<int>>&ans,vector<int>&ds){
        int n =nums.size();
        if(ind==n){
            sort(ds.begin(),ds.end());
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[ind]);
        uniqueSubsets2(ind+1,nums,ans,ds);
        ds.pop_back();
        uniqueSubsets2(ind+1,nums,ans,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        uniqueSubsets2(0,nums,ans,ds);
        vector<vector<int>>ans2;
        for(auto it=ans.begin();it!=ans.end();it++){
            ans2.push_back(*it);
        }
        return ans2;
    }
};