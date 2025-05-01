class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>prefixSum(n+1);
    //     prefixSum[0]=0;
    //     //if(n==1)return nums[0];
    //     for(int i=1;i<=n;i++)prefixSum[i]=nums[i-1]+prefixSum[i-1];
    //     int ma=*max_element(nums.begin(),nums.end());
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             ma=max(ma,prefixSum[j+1]-prefixSum[i]);
    //         }
    //     }
    //     return ma;
    // }

    int maxSubArray(vector<int>& nums){
        int n=nums.size();
        int sum=0;int mx=*max_element(nums.begin(),nums.end());
        if(n==1||mx<=0)return mx;
        for(int x:nums){
            sum+=x;
            if(sum<0)sum=0;
            mx=max(mx,sum);
        }
        return mx;
    }
};