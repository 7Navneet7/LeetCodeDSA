class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        // looking for subarrays with gcd k
        int cnt=0;int n=nums.size();
        for(int i=0;i<n;i++){
            int curGcd=0;
            for(int j=i;j<n;j++){
                curGcd=gcd(curGcd,nums[j]);
                if(curGcd<k)break;
                if(curGcd==k)cnt++;
            }
        }
        return cnt;
    }
};