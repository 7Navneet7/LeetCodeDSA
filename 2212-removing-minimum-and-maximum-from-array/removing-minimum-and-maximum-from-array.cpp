class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min1=*min_element(nums.begin(),nums.end());
        int max1=*max_element(nums.begin(),nums.end());
        int count=0,left,right;
        bool minfound=false,minfound2=false,maxfound=false,maxfound2=false;
        int leftfound=0,rightfound=0,separate=0;
       for(int i=0;i<nums.size();i++){
        
        if(nums[i]==min1){
            minfound=true;
        }
        if(nums[i]==max1){
            maxfound=true;
        }
        if(minfound and maxfound){
            leftfound=leftfound+i+1;
            break;
        }
       }
       for(int j=nums.size()-1;j>=0;j--){
        if(nums[j]==min1){
            minfound2=true;
        }
        if(nums[j]==max1){
            maxfound2=true;
        }
        if(minfound2 and maxfound2){
            rightfound=rightfound+nums.size()-j;
            break;
        }
       }

       for(int i=0;i<nums.size();i++){
        if(nums[i]==min1 or nums[i]==max1){
            separate=separate+i+1;
            break;
        }
       }
       for(int j=nums.size()-1;j>=0;j--){
        if(nums[j]==min1 or nums[j]==max1){
            separate=separate+nums.size()-j;
            break;
        }
       }
       return min(leftfound,min(rightfound,separate));
       



    }
};