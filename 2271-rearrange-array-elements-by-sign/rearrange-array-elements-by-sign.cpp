class Solution {
public:
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     int n=nums.size();
    //     if(nums[0]<0){
    //         for(int i=1;i<n;i++){
    //             if(nums[i]>0){
    //                 swap(nums[0],nums[i]);break;
    //             }
    //         }
    //     }
    //     for(int i=0;i<n-2;i+=1){
    //         if(nums[i]*nums[i+1]>0){
    //             //swap(nums[i+1],nums[i+2]);
    //             for(int j=i+2;j<n;j++){
    //                 if(nums[i+1]*nums[j]<0){
    //                     swap(nums[i+1],nums[j]);
    //                 }
    //             }
    //         }    
    //     }
    //     return nums;
        
    // }




    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos,neg;
        for(auto &it:nums){
            if(it<0)neg.push_back(it);
            else pos.push_back(it);
        }
        vector<int>ans(n);int i=0,j=0;
        for(int k=0;k<n;k+=1){
            if(k%2)ans[k]=neg[j++];
            else ans[k]=pos[i++];
        }
        return ans;
    }    
};