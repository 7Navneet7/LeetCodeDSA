class Solution {
public:
    // int countElements(vector<int>& nums, int k) {
    //     int n=nums.size();int cnt=0;
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<n-k;i++){
    //         if(i>0 && nums[i]==nums[i-1]){
    //             cnt--;
    //         }
    //         cnt++;
    //     }
    //     return cnt;
    // }

    

    // int countElements(vector<int>& nums, int k){
    //     int n=nums.size();
    //     set<int>st(nums.begin(),nums.end());
    //      if((st.size())-k>1)return st.size()-k;
    //      else return 0;
    //     //return st.size();
    // }

    int countElements(vector<int>& nums, int k){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int bound=nums[n-k];int cnt=0;
        for(int x:nums){
            if(x<bound)cnt++;
        }
        return cnt;
    }
};