class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int x:nums)mp[x]++;
        int n=nums.size();
        for(auto[key,value]:mp){
            if(value>n/2){
                return key;
            }
        }
        return -1;
    }
};