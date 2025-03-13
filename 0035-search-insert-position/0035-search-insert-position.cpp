class Solution {
public:
    // int searchInsert(vector<int>& nums, int target) {
    //     int n=nums.sze();
    //     int low=nums[0]; int high=nums[n-1];
    //     while(low < high){
    //         int mid=(low+high)/2;

    //     }
    // }

    int searchInsert(vector<int>&nums,int target){
        int n=nums.size();
        int ind=0;
        for(int i=0;i<n;i++){
            if(target<=nums[i]  ){
                ind=i;
                break;
            }
            if(i==n-1)ind=n;
        }
        return ind;
    }
};