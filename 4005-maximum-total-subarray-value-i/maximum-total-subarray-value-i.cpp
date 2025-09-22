using ll=long long;
class Solution {
    
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll ans=0;
        ans=(*max_element(nums.begin(),nums.end()))-(*min_element(nums.begin(),nums.end()));
            return ans*k;
    }
};