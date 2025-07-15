class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int n=nums.size();int sum=0;
        int mx=*max_element(nums.begin(),nums.end());
        int l=1,h=mx;
        while(l<=h){
            int m=(l+h)/2;
            sum=0;
            for(int x:nums)sum+=((x+m-1)/m);
            if(sum<=t)h=m-1;
            else l=m+1;
        }
        return l;
    }
};