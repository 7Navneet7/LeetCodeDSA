class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0]+0;
        for(int i=1;i<n;i++){
            if(i>mx)return 0;
            mx=max(mx,i+nums[i]);
        }
        return 1;
    }
};