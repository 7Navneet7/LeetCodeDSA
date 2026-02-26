class Solution {
public:
    bool valid(int a,int b,int c){
        return (a+b>c)&&(b+c>a)&&(a+c>b);
    }
    // int largestPerimeter(vector<int>& nums) {
    //     int n=nums.size();
    //     int ans=0;
    //     for(int i=0;i<n-2;i++){
    //         int j=i+1;int k=n-1;
    //         while(j<k){
    //             if(valid(nums[i],nums[j],nums[k])){
    //                 j++;
    //             }
    //             else{
    //                 k--;
    //             }
    //         }
    //     }
        
    // }

    int largestPerimeter(vector<int>& nums){
        int n=nums.size();sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            if(nums[i-1]+nums[i-2]>nums[i])return nums[i-1]+nums[i-2]+nums[i];
        }
        return 0;
    }
};