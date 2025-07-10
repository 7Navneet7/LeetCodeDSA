class Solution {
public:
    set<vector<int>>st;
    void permuteList(int ind,vector<vector<int>>&ans,vector<int>&nums){
        int n=nums.size();
        if(ind==n){
            if(st.find(nums)==st.end()){
                ans.push_back(nums);
                st.insert(nums);
            }
            return;
        }
        for(int j=ind;j<n;j++){
            swap(nums[ind],nums[j]);
            permuteList(ind+1,ans,nums);
            swap(nums[ind],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
         permuteList(0,ans,nums);
        return ans;
    }
};