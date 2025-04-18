class Solution {
public:
    void findComb(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        int n=arr.size();
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1])continue;

            if(target<arr[i])break;
            ds.push_back(arr[i]);
            findComb(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans; vector<int>ds;
        findComb(0,target,candidates,ans,ds);
        return ans;
        
    }
};