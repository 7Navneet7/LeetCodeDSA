class Solution {
public:
    // int minOperations(vector<int>& nums) {
    //     unordered_set<int>unique(nums.begin(),nums.end());
    //     int n=nums.size(),ans=0;
    //     for(int num:unique){
    //         if(num==0)continue;
    //         int i=0;
    //         while(i<n){
    //             if(nums[i]==num){
    //                 ans++;
    //                 while(i<n && nums[i]>=num)i++;
    //             }
    //             i++;
    //         }
    //     }
    //     return ans;
    // }

    int minOperations(vector<int>& nums){
        stack<int>st;int ans=0;
        for(int num:nums){
            while(!st.empty()&& num<st.top()){
                st.pop();
            }
            if(st.empty()||num>st.top()){
                if(num>0)ans++;
                st.push(num);
            }
        }
        return ans;
    }
};