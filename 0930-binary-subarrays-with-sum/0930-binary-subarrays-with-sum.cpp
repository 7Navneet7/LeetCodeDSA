class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int go) {
        //int n=num.size();
        return atmost(nums,go)-atmost(nums,go-1);
    }
    int atmost(vector<int>a,int ta){
        if(ta<0)return 0;
        int n=a.size();
        int l=0;int su=0;
        int ans=0;
        for(int r=0;r<n;r++){
            su+=a[r];
            while(su>ta && l<=r){
                su-=a[l];l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};