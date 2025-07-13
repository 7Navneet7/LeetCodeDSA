class Solution {
public:
    int start(vector<int>&nums,int key){
        int h=nums.size()-1,l=0;int ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==key){
                ans=m;h=m-1;
            }
            else if(nums[m]>key){
                h=m-1;
            }
            else{l=m+1;}
        }
        return ans;
    }
    int end(vector<int>&nums,int key){
        int l=0,h=nums.size()-1,ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==key){
                ans=m;l=m+1;
            }
            else if(nums[m]>key){h=m-1;}
            else{l=m+1;}
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int key) {
        return{start(nums,key),end(nums,key)};
    }
};