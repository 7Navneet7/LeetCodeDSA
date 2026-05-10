using ll=long long;
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& que) {
        int n=nums.size();vector<int>clos(n);
        clos[0]=1,clos[n-1]=n-2;
        for(int i=1;i<n-1;i++){
            clos[i]=abs(nums[i-1]-nums[i])<=abs(nums[i+1]-nums[i])?i-1:i+1;
        }
        vector<int>ans;
        vector<ll>inc(n),dec(n);
        inc[0]=0,dec[n-1]=0;
        //inc[n-1]=abs(nums[n-1]-nums[n-2]);

        for(int i=1;i<=n-1;i++){
            if(clos[i-1]==i)inc[i]=1+inc[i-1];
            else inc[i]=abs(nums[i]-nums[i-1])+inc[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(clos[i+1]==i)dec[i]=1+dec[i+1];
            else dec[i]=abs(nums[i]-nums[i+1])+dec[i+1];
        }
        for(auto it:que){
            int st=it[0],en=it[1];
            int cos=0;
            if(st<en){
                // while(st<en){
                //     if(clos[st]==st+1)cos+=1,st++;
                //     else cos+=abs(nums[st]-nums[st+1]),st++;
                // }
                cos+=(int)(inc[en]-inc[st]);
            }
            else{
                // while(st>en){
                //     if(clos[st]==st-1)cos+=1,st--;
                //     else cos+=abs(nums[st]-nums[st-1]),st--;
                // }
                cos+=(int)(dec[en]-dec[st]);
            }
            ans.push_back(cos);
        }
        return ans;
    }
};