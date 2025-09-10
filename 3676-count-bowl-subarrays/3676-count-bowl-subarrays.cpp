
using ll=long long;class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        stack<int>st;int i=0,n=nums.size();ll ans=0;
        while(i<n){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                st.pop();
                if(!st.empty())ans++;
            }
            st.push(i);i++;

        }
        return ans;
    }
};