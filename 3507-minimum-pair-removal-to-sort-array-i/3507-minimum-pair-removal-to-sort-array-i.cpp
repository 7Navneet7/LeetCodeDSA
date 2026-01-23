class Solution {
public:
    bool isit(vector<int>&nums){
        int s=nums.size();bool f=true;
        for(int i=0;i<s-1;i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int c=0;
        while(!isit(nums)){
            
        
            int n=nums.size();
            vector<int>numss(n);
            // for(int i=0;i<n-1;i++){
            //     numss[i]=nums[i]+nums[i+1];
            // }
            int min=INT_MAX;int ind=-1;
            for(int i=0;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<min){
                    min=sum;
                    ind=i;
                }    
            }
            nums[ind]=nums[ind]+nums[ind+1];
            // for(int i=ind+1;i<nums.size()-1;i++){
            //     nums[i]=nums[i+1];
            // }
            nums.erase(nums.begin()+ind+1);
            min=INT_MAX;
            c++;
        } 
        return c;
    }
};