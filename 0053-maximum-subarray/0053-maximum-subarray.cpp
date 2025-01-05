class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
        
    // }
    int maxSubArray(vector<int>&nums){
        int res=nums[0];
        int total=0;
        for(int x:nums){
            if(total<0)total=0;
            total+=x;
            res=max(res,total);
        }
        return res;
    }
};