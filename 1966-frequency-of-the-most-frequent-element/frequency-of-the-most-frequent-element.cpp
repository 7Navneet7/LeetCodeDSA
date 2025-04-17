class Solution {
public:
    // int maxFrequency(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end());
    //     int n=nums.size();
    //     int i=n-2;int c=0;
    //     while(k>=0&& i>=0){
    //         k-=nums[n-1]-nums[i];
    //         if(k>=0 ){
    //             c++;i--;
    //         }
    //     }
    //     return c+1;
        
    // }


    int maxFrequency(vector<int>& nums, int k){
        long i=0,sum=0,n=nums.size();long ans=1;
        sort(nums.begin(),nums.end());
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while((j-i+1)*nums[j]-sum>k){
                sum-=nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};