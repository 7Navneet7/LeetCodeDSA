class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return;
        }
        k=k%n;
        if(k>n){
            return;
        }
        // if(k<n){
        vector<int>tem;
        for(int i=n-k;i<n;i++){
            tem.push_back(nums[i]);
        }
        vector<int>nums2=nums;
        for(int i=k;i<n;i++){
            nums[i]=nums2[i-k];
        }
        for(int i=0;i<k;i++){
            nums[i]=tem[i];
        }
        // }
    }
};