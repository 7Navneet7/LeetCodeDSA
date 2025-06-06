class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permuteList({},nums);
    }

    vector<vector<int>>permuteList(vector<int>proces,vector<int>full){
        if(full.empty())return {proces};
        int num=full[0];
        vector<int>rest(full.begin()+1,full.end());
        vector<vector<int>>result;
        for(int i=0;i<=proces.size();i++){
            vector<int>temp=proces;
            temp.insert(temp.begin()+i,num);
            vector<vector<int>>partial=permuteList(temp,rest);
            result.insert(result.end(),partial.begin(),partial.end());
        }
        return result;
    }
};