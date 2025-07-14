class Solution {
public:
    int findMin(vector<int>& nums) {
       int n=nums.size(),l=0,h=n-1;int ans=INT_MAX;
       while(l<=h){
            int m=(l+h)/2;
            // if(nums[l]<=nums[h]){
            //     return nums[l];
            // }
            if(nums[l]<=nums[m]){
                ans=min(nums[l],ans);l=m+1;
            }
            else{
                ans=min(nums[m],ans);h=m-1;
            }
       }
       return ans;
    }
};