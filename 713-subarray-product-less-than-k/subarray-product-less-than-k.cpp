class Solution {
public:
    // int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    //     int i=0,ans=0,mul=1;
    //     for(int j=0;j<nums.size();j++){
    //         mul*=nums[j];
    //         while(mul>=k && mul>0){
    //             mul/=nums[i];
    //             i++;
    //         }
    //         if(mul!=0&& mul<k)ans++;
    //     }
    //     return ans;
        
    // }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),i=0,mul=1,cnt=0;
        if(k==0)return 0;
        for(int j=0;j<n;j++){
            mul*=nums[j];
            while(i<=j && mul>=k){
                mul/=nums[i];i++;
            }
            cnt+=(j-i+1);
        }
        return cnt;
    }
};