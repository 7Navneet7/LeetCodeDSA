class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;mp[0]=-1;int su=0;int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)su+=1;
            else su-=1;
            if(mp.count(su)){
                ans=max(ans,i-mp[su]);
            }
            else mp[su]=i;
        }
        return ans;
    }
};