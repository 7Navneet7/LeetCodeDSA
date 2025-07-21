class Solution {
public:
    int atmost(vector<int>&nums,int g){
        int res=0;int sum=0;int curr=0;int j=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            while(curr>g && j<=i){
                curr-=nums[j];j++;
            }
            res+=(i-j+1);
        }
        return res;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};