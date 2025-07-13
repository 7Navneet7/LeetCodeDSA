class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int>st;
        for(int x:nums)st.insert(pow(x,2));
        nums={};
        nums.assign(st.begin(),st.end());
        return nums;
    }
};