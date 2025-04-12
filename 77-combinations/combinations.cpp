class Solution {
public:
    void solve(int ind,int k,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
        //if(ind==nums.size()){
            if(k==0){
                ans.push_back(ds);
                return;
            }    
        //}
        for(int i=ind;i<nums.size();i++){
            if(k==0)break;
            ds.push_back(nums[i]);
            solve(i+1,k-1,nums,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums,ds;vector<vector<int>>ans;
        for(int i=1;i<=n;i++)nums.push_back(i);
        solve(0,k,nums,ans,ds);
        return ans;
        
    }
};