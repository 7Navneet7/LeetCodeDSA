class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>mp;
        for(int x:nums)mp[x]++;
        vector<int>ans;int i=0;
        while(mp.count(i)||mp.count(i+1)||mp.count(i+2)){
            while(mp[i]>0){
                ans.push_back(i);
                mp[i]--;
            }
            i++;
        }
        nums=ans;
    }
};