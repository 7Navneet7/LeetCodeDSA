class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n=nums.size();vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(ans.back()[1]<nums[i][0]){ans.push_back(nums[i]);}
            else{
                ans.back()[1]=max(nums[i][1],ans.back()[1]);
            }
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newnum) {
        int n=nums.size();
        if(n==0)return{newnum};
        for(int i=0;i<n;i++){
            if(nums[i][1]>=newnum[0] && nums[i][0]<=newnum[0]){
                nums[i][1]=max(nums[i][1],newnum[1]);
                nums[i][0]=min(nums[i][0],newnum[0]);break;
            }
            else{nums.push_back(newnum);}
        }
        return merge(nums);
    }
};