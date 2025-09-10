using ll=long long;
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int i=0,j=nums.size()-1;ll ans=0;
        sort(nums.begin(),nums.end());
        while(i<j){
            j--;ans+=nums[j];j--;i++;
        }
        return ans;
    }
};