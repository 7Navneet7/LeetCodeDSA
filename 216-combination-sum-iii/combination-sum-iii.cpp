class Solution {
public:
    void solve(int ind,int targ,int k,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
        //if(ind==nums.size()){
        if(k==0 && targ==0){
            ans.push_back(ds);
            return;
        }
        //}
        if(ind==nums.size()||k<0||targ<0)return;

        // for(int i=ind;i<nums.size();i++){
        //     if(k<0||targ<nums[ind])break;
        //     ds.push_back(nums[ind]);
        //     solve(i+1,targ-nums[i],k-1,nums,ans,ds);
        //     ds.pop_back();
        // }

        
        if(targ<=0)return;
            ds.push_back(nums[ind]);
            solve(ind+1,targ-nums[ind],k-1,nums,ans,ds);
            ds.pop_back();
        
            solve(ind+1,targ,k,nums,ans,ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums(9),ds;vector<vector<int>>ans;
        for(int i=0;i<9;i++){
            nums[i]=i+1;
        }    
        solve(0,n,k,nums,ans,ds);
        return ans;
    }
};