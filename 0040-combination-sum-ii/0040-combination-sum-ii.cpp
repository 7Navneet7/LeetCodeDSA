class Solution {
public:
    void backT(int idx,vector<int>cnd,int tar,vector<vector<int>>&ans,vector<int>&ds){
        if(tar==0){
            ans.push_back(ds);return;
        }
        if(idx==cnd.size())return;
        for(int i=idx;i<cnd.size();i++){
            if(i>idx && cnd[i]==cnd[i-1])continue;
            if(tar<cnd[i])break;
            ds.push_back(cnd[i]);
            backT(i+1,cnd,tar-cnd[i],ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cnd, int tar) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(cnd.begin(),cnd.end());
        backT(0,cnd,tar,ans,ds);
        return ans;
    }
};