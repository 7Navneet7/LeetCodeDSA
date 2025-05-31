class Solution {
public:
    // int minOperations(vector<int>& nums) {
    //     int ans=0;
    //     int n=nums.size();
    //     for(int i=1;i<n;i++){
    //         if(nums[i]<=nums[i-1]){
    //             ans+=nums[i-1]+1-nums[i];
    //             nums[i]=nums[i-1]+1;
    //         }
    //     }
    //     return ans;
        
    // }

    int minOperations(vector<int>& nums) {
        int n=nums.size();int ops=0;int k;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])continue;
            else{
                k=nums[i];
                nums[i]=nums[i-1]+1;
                ops+=(nums[i]-k);
            }
        }
        return ops;
    }    
};