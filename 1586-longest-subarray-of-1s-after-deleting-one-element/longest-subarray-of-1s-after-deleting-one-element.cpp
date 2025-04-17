class Solution {
public:
    // int longestSubarray(vector<int>& nums) {
    //     long i=0;long ans=0;long cnt=0;long n=nums.size();long ind=-1;
    //     for(long j=0;j<n;j++){
    //         bool f=0;
    //         while(cnt<1 && j<n-1){
    //             if(nums[j]==0){
    //                 f=1;
    //                 cnt++;ind=j+1;
    //             }
    //             j++;
    //         }
    //         if(f)ans=max(ans,j-i);
    //         else ans=max(ans,j-i+1);
    //         i=ind;
    //         cnt=0;
    //     }
    //     return ans;
    // }


    int longestSubarray(vector<int>& nums) {
        long i=0,ans=0,cnt=0;long n=nums.size();
        for(long j=0;j<n;j++){
            cnt+=nums[j]==0;
            while(cnt>1){
                cnt-=nums[i++]==0;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};