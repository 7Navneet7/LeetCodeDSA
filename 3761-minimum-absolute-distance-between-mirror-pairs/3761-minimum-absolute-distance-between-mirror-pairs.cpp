class Solution {
public:

    int rev(int nu){
        int res=0;
        while(nu>0){
            if(nu%10==0)continue;
            res=res*10+nu%10;
            nu/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int>mp;
        mp[rev(nums[0])]=0;
        int n=nums.size();int ans=INT_MAX;
        for(int i=1;i<n;i++){
            if(mp.count(nums[i]))ans=min(ans,abs(mp[nums[i]]-i));
                
            
            mp[rev(nums[i])]=i;
        }
        if(ans!=INT_MAX)return ans;
        else return -1;
    }
};