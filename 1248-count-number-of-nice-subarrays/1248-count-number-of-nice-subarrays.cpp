class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
   
    int atmost(vector<int>a,int k){
        int n=a.size();
        int l=0;int od=0;
        if(k<0)return 0;
        int ans=0;
        for(int r=0;r<n;r++){
            if(a[r]& 1)od++;
            if(od>k){
                while(od>k && l<=r){
                    if(a[l]&1)od--;
                    l++;
                }
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};