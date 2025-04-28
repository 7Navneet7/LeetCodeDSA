class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int i=0;int j=nums.size()-1;vector<int>ans;
    //     vector<int>nums2=nums;
    //     sort(nums.begin(),nums.end());      
    //     while(i<j){
    //         int sum=nums[i]+nums[j];
    //         if(sum==target){
    //             auto it1=find(nums2.begin(),nums2.end(),nums[i]);
    //             ans.push_back(it1-nums2.begin());
    //             auto it2=find(nums2.begin(),nums2.end(),nums[j]);
    //             ans.push_back(it2-nums2.begin());
    //             break;
    //         }
    //         else if(sum<target){
    //             i++;
    //         }
    //         else{
    //             j--;
    //         }
            
    //     }
    //     return ans;
        
    // }


    vector<int> twoSum(vector<int>& nums, int target){
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int need=target-num;
            if(mp.find(need)!=mp.end()){
                return {i,mp[need]};
            }
            mp[num]=i;
        }
        return {-1,-1};
    }
};