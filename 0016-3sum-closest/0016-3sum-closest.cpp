class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) {
        int mn=INT_MAX;int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int l=i+1,r=n-1;
            while(l<r){
                int su=nums[i]+nums[l]+nums[r];
                int diff=tar-su;
                if(diff==0){
                    return su;
                }
                else if(diff>0){
                    if(diff<mn){ans=su;mn=diff;}
                    l++;
                }
                else {r--;if(abs(diff)<mn){ans=su;mn=abs(diff);}}
            }
        }
        return ans;
        
    }
};