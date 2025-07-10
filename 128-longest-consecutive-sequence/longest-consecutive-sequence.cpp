class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int>st(nums.begin(),nums.end());
        vector<int>arr(st.begin(),st.end());
        if(arr.empty())return 0;
        int ma=1,cnt=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]+1){
                cnt++;ma=max(ma,cnt);
            }
            else{
                cnt=1;
            }
        }
        return ma;
    }
};