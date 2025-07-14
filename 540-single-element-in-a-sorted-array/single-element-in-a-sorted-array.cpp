class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();int xo=0;
        for(int x:nums)xo^=x;
        return xo;
    }
};