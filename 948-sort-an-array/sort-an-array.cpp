class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high){
        if(low>=high)return;
        int l=low,r=mid+1,k=0;
        vector<int>arr(high-low+1,0);
        while(l<=mid && r<=high)arr[k++]=nums[l]<nums[r]?nums[l++]:nums[r++];
        while(l<=mid)arr[k++]=nums[l++];
        while(r<=high)arr[k++]=nums[r++];
        for(k=0;k<high-low+1;k++){
            nums[low+k]=arr[k];
        }
    }

    void mergeSort(vector<int>&nums,int low,int high){
        if(low>=high)return;
        int mid=(low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);return nums;
    }
};