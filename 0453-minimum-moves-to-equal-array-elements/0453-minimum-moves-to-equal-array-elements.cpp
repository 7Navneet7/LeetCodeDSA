class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mov=0;
        for(auto &it:nums)mov+=(it-mn);
        return mov;
        
    }
};