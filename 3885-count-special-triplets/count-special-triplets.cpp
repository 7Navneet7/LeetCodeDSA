const int MOD=1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();long long res=0;
        map<int,int>l,r;
        for(int val:nums)r[val]++;
        
        for(int j=0;j<n;j++){
            int mid=nums[j];
            r[mid]--;
            int leftOcc=l[2*mid];
            int rightOcc=r[2*mid];
            res=(res+1LL* leftOcc*rightOcc)%MOD;
            l[mid]++;
        }
        return res;
        
    }
};