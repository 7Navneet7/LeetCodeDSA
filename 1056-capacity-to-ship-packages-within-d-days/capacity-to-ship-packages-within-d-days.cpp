class Solution {
public:
    int days(vector<int>&nums,int cap){
        int cnt=1,curr=0;
        for(int x:nums){
            if(curr+x>cap){
                cnt++;curr=0;
            }
            curr+=x;
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& nums, int d) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int l=*max_element(nums.begin(),nums.end());
        int h=sum;
        while(l<=h){
            int m=(l+h)/2;
            int ds=days(nums,m);
            if(ds<=d){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return l;

    }
};