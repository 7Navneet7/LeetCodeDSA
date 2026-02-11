class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        
        //int i=0;int mx=-1;
        int mx=0;
        for(int i=0;i<n;i++){
            set<int>od,ev;
            for(int j=i;j<n;j++){
                if(nums[j]&1)od.insert(nums[j]);
                else ev.insert(nums[j]);
                if(ev.size()==od.size())mx=max(mx,j-i+1);
            }

        }
        return mx;
    }
};