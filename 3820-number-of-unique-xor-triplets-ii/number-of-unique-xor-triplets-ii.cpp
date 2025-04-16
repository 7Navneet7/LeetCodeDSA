class Solution {
public:


    // void solve(int ind,int t,vector<int>&nums,set<int>&xo,int op){
    //     if(t==3){
    //         xo.insert(op);return;
    //     } 

    //     if (ind >= nums.size() || nums.size() - ind <3-t-1) return;
        
    //     // if(ind==nums.size()){
            
    //     //     return;
    //     // }
    //     for(int i=ind;i<nums.size();i++){
    //         if(i>ind && nums[i]==nums[i-1])continue;
    //         if(t>2)break;
    //         op=op^nums[i];
    //         solve(i,t+1,nums,xo,op);
    //         op=op^nums[i];
            
    //     }
    //     // if(t<3){
    //     //     op^=nums[ind];
    //     //     solve(ind,t+1,nums,xo,op);
    //     //     op^=nums[ind];
    //     // }
    //     // solve(ind+1,t,nums,xo,op);
        
    // }
    // int uniqueXorTriplets(vector<int>& nums) {
    //     if(nums.size()<3)return nums.size();
    //     int op=0;set<int>xo;
    //     solve(0,0,nums,xo,op);
    //     return xo.size();
    // }


    int uniqueXorTriplets(vector<int>& nums){
        int n=nums.size();unordered_set<int>st1,st2;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st1.insert(nums[i]^nums[j]);
            }
        }
        for(int x:st1){
            for(int j=0;j<n;j++){
                st2.insert(x ^ nums[j]);
            }
        }
        return st2.size();
    }
};