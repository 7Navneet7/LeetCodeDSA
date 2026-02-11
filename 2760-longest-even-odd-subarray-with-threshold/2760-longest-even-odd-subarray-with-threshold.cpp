class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int thr) {
        int n=nums.size();
        int ans=0;
        for(int l=0;l<n;l++){

            if((nums[l]%2==0)&&(nums[l]<=thr) ){
                int r=l;
                while(r<n-1 && ((nums[r]%2)!=(nums[r+1]%2))&&(nums[r+1]<=thr)){
                    r++;
                }
                ans=max(ans,r-l+1);
            }
        }
        return ans;
        
    }
};