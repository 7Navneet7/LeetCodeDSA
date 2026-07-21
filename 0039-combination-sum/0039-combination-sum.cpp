class Solution {
public:
    void backT(int idx,vector<int>&cnd,int tar,vector<vector<int>>&ans,vector<int>&ds){
        if(tar==0){
            ans.push_back(ds);return;
        }
        if(idx==cnd.size())return;
        
        if(tar>=cnd[idx]){
            ds.push_back(cnd[idx]);
            backT(idx,cnd,tar-cnd[idx],ans,ds);
            ds.pop_back();
        }
        backT(idx+1,cnd,tar,ans,ds);

    }
    vector<vector<int>> combinationSum(vector<int>& cnd, int tar) {
        vector<vector<int>>ans;
        vector<int>ds;
        backT(0,cnd,tar,ans,ds);
        return ans;
    }
};