using ll=long long;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();sort(nums.begin(),nums.end());
        int r=1;int mx=-1;
        for(int i=0;i<n;i++){
            while(r<n && 1ll*nums[i]*k>=1ll*nums[r]){
                r++;
            }
            mx=max(mx,r-i);
        }
        return (n-mx);
    }
};