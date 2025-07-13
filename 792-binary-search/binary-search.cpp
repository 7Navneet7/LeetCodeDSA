class Solution {
public:
    int finds(vector<int>&nums,int low,int high,int targ){
        int mid=(low+high)/2;
        if(low>high)return -1;
        else if(nums[mid]==targ)return mid;
        else if(nums[mid]>targ){
           return finds(nums,low,mid-1,targ);
        }
        else{return finds(nums,mid+1,high,targ);}
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return finds(nums,0,n-1,target);
    }
};