class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ld=0,hd=nums.size()-1;int ind=0;
        while(ld<hd){
            int md=(ld+hd)/2;
            if(nums[md+1]>nums[md]){
                ld=md+1;
            }
            else hd=md;
        }
        return ld;
    }
};