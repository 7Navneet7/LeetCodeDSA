class Solution {
public:
    // void generate(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
    //     if(ind==nums.size()){ans.push_back(ds);return;}
    //     ds.push_back(nums[ind]);
    //     generate(ind+1,nums,ds,ans);
    //     ds.pop_back();
    //     generate(ind+1,nums,ds,ans);
    // }
    // void nextPermutation(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>ans;
    //     vector<int>ds;
    //     generate(0,nums,ds,ans);
    //     auto it=find(ans.begin(),ans.end(),nums);
    //     int idx=(it-ans.begin()+1+ans.size()) % ans.size();
    //     for(int j=0;j<nums.size();j++){
    //         cout<<ans[idx][j];
    //     }
        
    // }



    void nextPermutation(vector<int>& nums) {
    //     int n=nums.size();
    //     int ind=-1;
    //     for(int i=n-2;i>=0;i--){
    //         if(nums[i]<nums[i+1]){
    //             ind=i;break;
    //         }
    //     }
    //     if(ind==-1){
    //         reverse(nums.begin(),nums.end());
    //         return ;
    //     }
    //     //int mx=max_element(nums.begin()+ind,nums.end())-nums.begin();
    //     for(int i=n-1;i>ind;i--){
    //         if(nums[ind]<nums[i]){
    //             swap(nums[ind],nums[i]);break;
    //         }
    //     }
    //     reverse(nums.begin()+ind+1,nums.end());
        
      
    //     //for(auto &it:nums)cout<<it;
        next_permutation(nums.begin(),nums.end());
     }    
};