class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int>frq,mp;
        for(int x:nums){
            frq[x]++;
        }
        for(auto[k,v]:frq){
            mp[v]++;
        }
        for(auto x:nums){
            if(mp[frq[x]]==1)return x;
        }
        return -1;
    }
};