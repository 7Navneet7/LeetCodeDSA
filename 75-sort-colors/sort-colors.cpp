class Solution {
public:
    void sortColors(vector<int>& nums) {
        // map<int,int>mp;
        // for(int x:nums)mp[x]++;
        // vector<int>ans;int i=0;
        // while(mp.count(i)||mp.count(i+1)||mp.count(i+2)){
        //     while(mp[i]>0){
        //         ans.push_back(i);
        //         mp[i]--;
        //     }
        //     i++;
        // }
        // nums=ans;
        int l=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[l],nums[m]);l++;m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m],nums[h]);h--;
            }
        }
    }
};