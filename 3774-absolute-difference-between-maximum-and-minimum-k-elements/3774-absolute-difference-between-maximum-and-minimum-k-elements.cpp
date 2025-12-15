class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0;int n=nums.size();
        for(int i=0;i<k;i++){
            s+=nums[i];
            s-=nums[n-i-1];
        }
        return abs(s);
    }
};