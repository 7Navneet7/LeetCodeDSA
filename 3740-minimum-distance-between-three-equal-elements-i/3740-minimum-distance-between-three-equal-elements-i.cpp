class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return -1;
        int mn=INT_MAX;bool f=0;
        for(int i=0;i<n-2;i++){
            //if(i+1>n-1)break;
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j]&&nums[j]==nums[k] && nums[i]==nums[k]){
                    int dif=abs(j-i)+abs(k-j)+abs(i-k);f=1;
                    mn=min(mn,dif);
                    }
                }
            }
        }
        if(f)return mn;
        else return -1;
    }
};