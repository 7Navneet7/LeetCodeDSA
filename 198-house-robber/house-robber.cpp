class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>robb(n+1),skip(n+1);
        for(int i=0;i<n;i++){
            robb[i+1]=nums[i]+skip[i];
            skip[i+1]=max(robb[i],skip[i]);
        }
        return max(robb[n],skip[n]);
    }
};