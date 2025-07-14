class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int n=nums.size(),l=0,h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==tar)return true;
            if(nums[l]==nums[m]&&nums[m]==nums[h]){
                l++;h--;continue;
            }
            if(nums[l]<=nums[m]){
                if(nums[l]<=tar && tar<=nums[m])h=m-1;
                else l=m+1;
            }
            else{
                if(nums[m]<=tar && tar<=nums[h])l=m+1;
                else h=m-1;
            }
        }
        return false;
    }
};